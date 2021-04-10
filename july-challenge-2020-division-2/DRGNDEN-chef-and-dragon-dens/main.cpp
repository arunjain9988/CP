#include <bits/stdc++.h>  // This will work only for g++ compiler. 


#define loop(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define floop(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define rloop(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)

//short hand for usual tokens
#define pb push_back

// to be used with algorithms that processes a container Eg: find(all(c),42)
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal

// traversal function to avoid long template definition. Now with C++11 auto alleviates the pain.
#define tr(c,i) for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)

using namespace std;

// Shorthand for commonly used types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

int n,q;
int a,b,c;
ll k;

struct Node{
    int start;
    int top;
    ll ans;
    Node() {
        start = 0;
        top = 0;
        ans = 0;
    }
    Node(int s,int t,ll aa) {
        start = s;
        top = t;
        ans = aa;
    }
};

Node Tree[800005];
Node Tree2[800005];

ll H[200005];
ll A[200005];
ll H2[200005];
ll A2[200005];

Node merge(const Node &fnode,int sid) {
    if (H[fnode.top]<H[Tree[sid].start]) {
        return Node(fnode.start,Tree[sid].top,fnode.ans+Tree[sid].ans); 
    }
    else if (H[Tree[sid].top]<=H[fnode.top]) {
        return fnode;
    }
    else {
        return merge(merge(fnode,sid*2),sid*2+1);
    }
}

Node merge2(const Node &fnode,int sid) {
    if (H2[fnode.top]<H2[Tree2[sid].start]) {
        return Node(fnode.start,Tree2[sid].top,fnode.ans+Tree2[sid].ans); 
    }
    else if (H2[Tree2[sid].top]<=H2[fnode.top]) {
        return fnode;
    }
    else {
        return merge2(merge2(fnode,sid*2),sid*2+1);
    }
}


void init(int node = 1, int start = 1, int end = n){
    if (start==end) {
        Tree[node] = {start,start,A[start]};
    }
    else {
        int mid = (start+end)/2;
        init(node*2,start,mid);
        init(node*2+1,mid+1,end);
        Tree[node] = merge(Tree[node*2],node*2+1);
    }
}


void init2(int node = 1, int start = 1, int end = n){
    if (start==end) {
        Tree2[node] = {start,start,A2[start]};
    }
    else {
        int mid = (start+end)/2;
        init2(node*2,start,mid);
        init2(node*2+1,mid+1,end);
        Tree2[node] = merge2(Tree2[node*2],node*2+1);
    }
}

pair<Node,int> query(int node,int start, int end, int l, int h) {
    if ( start>=l && end<=h ) {
        return {Tree[node],node};
    }
    else if (h<start || l>end ) {
        return {Node(0,0,0),0};
        // return Node(Tree[node].start,0,0);
    }
    else {
        int mid = (start+end)/2;
        pair<Node,int> n1 = query(node*2,start,mid,l,h);
        pair<Node,int> n2 = query(node*2+1,mid+1,end,l,h);
        if (n1.first.top==0) return n2;
        if (H[n1.first.top]<H[n2.first.start]) {
            return {Node(n1.first.start,n2.first.top,n1.first.ans+n2.first.ans),node};
        }
        else if (H[n1.first.top]>=H[n2.first.top]) {
            return n1;
        }
        // return merge(n1,node*2+1);
        return {merge(n1.first,n2.second),node};
    }
}

pair<Node,int> query2(int node,int start, int end, int l, int h) {
    if ( start>=l && end<=h ) {
        return {Tree2[node],node};
    }
    else if (h<start || l>end ) {
        return {Node(0,0,0),0};
    }
    else {
        int mid = (start+end)/2;
        pair<Node,int> n1 = query2(node*2,start,mid,l,h);
        pair<Node,int> n2 = query2(node*2+1,mid+1,end,l,h);
        if (n1.first.top==0) return n2;
        if (H2[n1.first.top]<H2[n2.first.start]) {
            return {Node(n1.first.start,n2.first.top,n1.first.ans+n2.first.ans),node};
        }
        else if (H2[n1.first.top]>=H2[n2.first.top]) {
            return n1;
        }
        return {merge2(n1.first,node*2+1),node};
    }
}

void update1(int node,int start,int end,int idx,ll value){
    if (node>800004 || node<0) return;
    if (start==end && start==idx) {
        Tree[node].ans=value;
    }
    else if (idx>=start && idx<=end) {
        // Tree[node].ans+=value;
        int mid = (start+end)/2;
        update1(node*2,start,mid,idx,value);
        update1(node*2+1,mid+1,end,idx,value);
        Tree[node] = merge(Tree[node*2],node*2+1);
    }
}

void update2(int node,int start,int end,int idx,ll value){
    if (node>800004 || node<0) return;
    if (start==end && start==idx) {
        Tree2[node].ans=value;
    }
    else if (idx>=start && idx<=end) {
        // Tree2[node].ans+=value;
        int mid = (start+end)/2;
        update2(node*2,start,mid,idx,value);
        update2(node*2+1,mid+1,end,idx,value);
        Tree2[node] = merge2(Tree2[node*2],node*2+1);
    }
}

int main() {
    // freopen("tests/user/6.in", "r", stdin);
    // freopen("tests/user/ans.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout << fixed;
    cin>>n>>q;
    H[0]=0;
    H2[0]=0;
    A[0]=0;
    A2[0]=0;
    loop(i,1,n+1) {
        cin>>H[i];
        H2[n-i+1]=H[i];
    }
    loop(i,1,n+1) {
        cin>>A[i];
        A2[n-i+1]=A[i];
    }



    if ((ll)n*q<10000000) {

        loop(i,0,q) {
            cin>>a;
            if (a==1) {
                cin>>b>>k;
                A[b]=k;
            }
            else {
                cin>>b>>c;
                if (c<=b) {
                    ll ans=A[c];
                    ll cur = c;
                    c++;
                    while(c<=b) {
                        if (H[c]>H[cur]) {
                            ans += A[c];
                            cur = c;
                        }
                        c++;
                    }
                    if (cur == b) {
                        cout<<ans<<'\n';
                    }
                    else {
                        cout<<-1<<'\n';
                    }
                }
                else // c>b 
                {

                    ll ans=A[c];
                    ll cur = c;
                    c--;
                    while(c>=b) {
                        if (H[c]>H[cur]) {
                            ans += A[c];
                            cur = c;
                        }
                        c--;
                    }
                    if (cur == b) {
                        cout<<ans<<'\n';
                    }
                    else {
                        cout<<-1<<'\n';
                    }
                }
            }
        }
    }



    else {
        init();
        init2();
        Tree[0]={0,0,0};
        Tree2[0]={0,0,0};
        loop(i,0,q) {
            cin>>a;
            if (a==1) {
                cin>>b>>k;
                // ll diff1 = k-A[b];
                // ll diff2 = k-A2[(n-b+1)];
                A[b]=k;
                A2[(n-b)+1]=k;
                update1(1,1,n,b,k);
                update2(1,1,n,(n-b)+1,k);
                // A[b]=k;
            }
            else {
                cin>>b>>c;
                if (c==b) {
                    cout<<A[c]<<'\n';
                }
                else if (c<b) {
                    Node ans = query(1,1,n,c,b).first;
                    if (ans.top==b) cout<<ans.ans;
                    else cout<<-1;
                    cout<<'\n';
                }
                else // c>b 
                {
                    Node ans = query2(1,1,n,(n-c)+1,(n-b)+1).first;
                    if (ans.top==((n-b)+1)) cout<<ans.ans;
                    else cout<<-1;
                    cout<<'\n';
                }
            }
        }

    }

    return 0;
    
}
