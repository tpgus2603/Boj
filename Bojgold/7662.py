import sys
import heapq
from collections import defaultdict

t=int(input())

for i in range(t):
  min_heap=[]
  max_heap=[]
  dir=defaultdict(int)
  k=int(input())
  for j in range(k):
    a=input().split()
    temp=a[0]
    num=int(a[1])
    if temp=='I':
      heapq.heappush(max_heap,-num)
      heapq.heappush(min_heap,num)
      dir[num]+=1
    else:
      if num==1:
        if max_heap:
          while max_heap and dir[-max_heap[0]]==0:
              heapq.heappop(max_heap)
          if max_heap:
            max_val=-heapq.heappop(max_heap)
            dir[max_val]-=1
            if dir[max_val]==0:
              dir.pop(max_val)
      else:  # Remove from min-heap
        if min_heap:
            while min_heap and dir[min_heap[0]] == 0:
                heapq.heappop(min_heap)
            if min_heap:
              min_val=heapq.heappop(min_heap)
              dir[min_val]-=1
              if dir[min_val]==0:
                dir.pop(min_val)
  keys_to_remove = [key for key, value in dir.items() if value == 0]
  for key in keys_to_remove:
      del dir[key]
  if not dir:
    print("EMPTY")
  else:
    min_key=min(dir.keys())
    max_key=max(dir.keys())
    print(max_key,min_key)



