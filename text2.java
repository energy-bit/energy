public class text2{
	public static void main(String [] args)  {  
      int[] arr={25,24,12,76,101,96,28};
                     int i = 0;
	for (i = 0; i < arr.length - 1; i++)
	{
		int j = 0;
		for (j = 0; j<arr.length - 1 - i; j++)
		{

			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
for(i=0;i<arr.length;i++)
{
System.out.println(arr[i]);
}
}
}