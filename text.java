public class text{
	public static void main(String [] args)  {  
      int[] arr={25,24,12,76,101,96,28};

        for (int i = 0; i < arr.length - 1; i++)
 { 
            int minIndex = i;                      
            for (int j = i + 1; j < arr.length; j++) 
{  
                minIndex = arr[j] < arr[minIndex] ? j : minIndex;
            }
            int temp = arr[i];          
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }

for(int i=0;i<arr.length;i++)
{
 Stytem.out.println(arr[i])；
}
}
