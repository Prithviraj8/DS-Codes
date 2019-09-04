import java.util.Arrays;
class ArrayFreq
{
public static void countFreq(boolean visited[], int arr[], int n)
{


    for (int i = 0; i < n; i++) {

        if (visited[i] == true)
            continue;

        int count = 1;
        // Counting element frequency
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        System.out.println(arr[i] + " " + count);
    }
}
public static void main(String []args)
{

    int arr[] = new int[]{ 10, 10, 20, 20, 20, 10, 5, 5 };
    int n = arr.length;
    boolean visited[] = new boolean[n];
    for (int i =0;i<n;i++) {
      visited[i] = false;
    }
    countFreq(visited, arr, n);


  }
}
