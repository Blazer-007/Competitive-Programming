static void sieve(int A)
{
       int[] isp=new int[A+1];
        
        for(int i=2;i*i<=A;i++)
        {
            if(isp[i]==0)
            {
                for(int j=i*i;j<=A;j+=i)
                {
                    isp[j]=1;
                }
            }
        }

System.out.println(“Prime numbers from 1 to “+A+” are-“);

 for(int i=2;i<=A;i++)
{
	if(isp[i]==0)
	{
		System.out.print(i+” “);
	}
}
}
