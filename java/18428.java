import java.io.*;
import java.util.*;

public class Main {
    // Grid representation
    static short[][] arr;
    static int n;
    
    // Lists to store teacher and empty positions
    static List<int[]> teachers = new ArrayList<>();
    static List<int[]> empties = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        // Use BufferedReader for efficient input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        // Read grid size
        n = Integer.parseInt(br.readLine());
        arr = new short[n][n];
        
        // Read grid and populate teachers and empty spaces
        for(int i = 0; i < n; i++) {
            String[] tokens = br.readLine().split(" ");
            for(int j = 0; j < n; j++) {
                char temp = tokens[j].charAt(0);
                switch(temp) {
                    case 'X':
                        arr[i][j] = 0;
                        empties.add(new int[]{i, j});
                        break;
                    case 'S':
                        arr[i][j] = 1;
                        break;
                    case 'T':
                        arr[i][j] = 2;
                        teachers.add(new int[]{i, j});
                        break;
                    default:
                        // Handle other characters if necessary
                        break;
                }
            }
        }

        boolean ans = false;
        int size = empties.size();
        
        // Iterate over all combinations of three empty positions to place obstacles
        for(int i = 0; i < size && !ans; i++) {
            for(int j = i + 1; j < size && !ans; j++) {
                for(int k = j + 1; k < size && !ans; k++) {
                    // Place obstacles
                    int[] pos1 = empties.get(i);
                    int[] pos2 = empties.get(j);
                    int[] pos3 = empties.get(k);
                    arr[pos1[0]][pos1[1]] = 3;
                    arr[pos2[0]][pos2[1]] = 3;
                    arr[pos3[0]][pos3[1]] = 3;

                    // Check if this obstacle placement blocks all teachers' views
                    if(isValid()) {
                        ans = true;
                        break;
                    }

                    // Remove obstacles for next iteration
                    arr[pos1[0]][pos1[1]] = 0;
                    arr[pos2[0]][pos2[1]] = 0;
                    arr[pos3[0]][pos3[1]] = 0;
                }
            }
        }

        // Output the result
        System.out.println(ans ? "YES" : "NO");
    }

    // Method to check if all teachers cannot see any students
    static boolean isValid() {
        for(int[] teacher : teachers) {
            if(canSeeStudent(teacher[0], teacher[1])) {
                return false; // If any teacher can see a student, this placement is invalid
            }
        }
        return true; // All teachers are blocked from seeing students
    }

    // Method to check if a specific teacher can see any student
    static boolean canSeeStudent(int x, int y) {
        // Directions: left, right, up, down
        // Left
        int i = y - 1;
        while(i >= 0) {
            if(arr[x][i] == 1) return true; // Student found
            if(arr[x][i] == 3) break; // Obstacle blocks the view
            i--;
        }
        // Right
        i = y + 1;
        while(i < n) {
            if(arr[x][i] == 1) return true;
            if(arr[x][i] == 3) break;
            i++;
        }
        // Up
        int j = x - 1;
        while(j >= 0) {
            if(arr[j][y] == 1) return true;
            if(arr[j][y] == 3) break;
            j--;
        }
        // Down
        j = x + 1;
        while(j < n) {
            if(arr[j][y] == 1) return true;
            if(arr[j][y] == 3) break;
            j++;
        }
        return false; // No students seen by this teacher
    }
}
 18428 {
  
}
