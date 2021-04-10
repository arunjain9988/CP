answer = 0
modulo = 10**9 +7
bits = [False]*10
N=int(input())
A=[0]*N
# for i in range(N-1,-1,-1):
#     A[i]=int(input())
p=input()
A=p.split(' ')
for k in range(len(A)):
    A[k]=int(A[k])

# print(A)
no_of_subsets=2**N
# print('no_of_subsets',no_of_subsets)#debug
for _ in range(1,no_of_subsets):
    bits=[False]*10
    shift=0
    i=_
    flag=True
    while(i>0):
        # print('i',i)#debug
        # print('1<<shift',1<<shift)#debug
        if i&1<<shift:
            temp=A[shift]
            bitstemp=[False]*10
            while(temp>0):
                a=temp%10
                bitstemp[a]=True
                temp//=10
            for z in range(10):
                if bits[z] and bitstemp[z]:
                    flag=False
            if not flag:
                break
            for z in range(10):
                bits[z] = (bitstemp[z] or bits[z])
            i = i^(1<<shift)
        shift+=1
    if flag:
        answer=(answer+1)%modulo

print(answer)
