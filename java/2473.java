import java.io.*;
import java.util.*;
 
class Pair {
    int first, second;
    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
 
public class Main {
    public static void main(String[] args) throws Exception {
        // 빠른 입출력을 위한 BufferedReader, StringTokenizer 사용
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
 
        int n = Integer.parseInt(st.nextToken());
        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
 
        // 두 용액의 합과 해당 인덱스 쌍을 저장하는 리스트
        ArrayList<Integer> sumArr = new ArrayList<>();
        ArrayList<Pair> idxList = new ArrayList<>();
 
        // 모든 i<j에 대해 두 용액의 합을 저장함
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                sumArr.add(arr[i] + arr[j]);
                idxList.add(new Pair(i, j));
            }
        }
 
        long ans = (long)4e9; // 충분히 큰 값으로 초기화 (4e9)
        int[] ansArr = new int[3];
 
        // sumArr의 각 원소에 대해 -cur를 찾는다.
        for (int i = 0, len = sumArr.size(); i < len; i++) {
            int cur = sumArr.get(i);
            int x = arr[idxList.get(i).first];
            int y = arr[idxList.get(i).second];
 
            // lower_bound: Arrays.binarySearch 사용 (정확한 값이 없으면 음수 리턴)
            int target = -cur;
            int temp = lowerBound(arr, target);
 
            // 후보 인덱스들에 대해 조건 검증 (temp, temp+1, temp-1)
            // temp가 n이면 마지막 원소 인덱스로 조정
            if (temp == n) {
                temp = n - 1;
            }
            // temp+1 후보
            if (temp + 1 < n && Math.abs((long)cur + arr[temp + 1]) < Math.abs(ans)
                    && arr[temp + 1] != x && arr[temp + 1] != y) {
                ans = Math.abs((long)cur + arr[temp + 1]);
                ansArr[0] = x;
                ansArr[1] = y;
                ansArr[2] = arr[temp + 1];
            }
            // temp 후보
            if (Math.abs((long)cur + arr[temp]) < Math.abs(ans)
                    && arr[temp] != x && arr[temp] != y) {
                ans = Math.abs((long)cur + arr[temp]);
                ansArr[0] = x;
                ansArr[1] = y;
                ansArr[2] = arr[temp];
            }
            // temp-1 후보
            int t2 = temp - 1;
            if (t2 >= 0) {
                if (Math.abs((long)cur + arr[t2]) < Math.abs(ans)
                        && arr[t2] != x && arr[t2] != y) {
                    ans = Math.abs((long)cur + arr[t2]);
                    ansArr[0] = x;
                    ansArr[1] = y;
                    ansArr[2] = arr[t2];
                }
            }
        }
 
        // 최종 결과 배열을 오름차순 정렬하여 출력
        Arrays.sort(ansArr);
        StringBuilder sb = new StringBuilder();
        for (int t : ansArr) {
            sb.append(t).append(" ");
        }
        System.out.println(sb.toString().trim());
    }
 
    // lower_bound 구현: arr에서 target 이상의 첫 인덱스를 반환
    static int lowerBound(int[] arr, int target) {
        int lo = 0, hi = arr.length;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] >= target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
}
