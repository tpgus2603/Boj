def hanoi(cur,fro,by,to):
  if cur==1:
    print(f"{fro} {to}")
    return
  hanoi(cur-1,fro,to,by)
  print(f"{fro} {to}")
  hanoi(cur-1,by,fro,to)

n=int(input())
print(2**(n)-1)
if n<=20:
  hanoi(n,1,2,3)

