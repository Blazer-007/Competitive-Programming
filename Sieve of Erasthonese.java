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

// if isp[i]=0 then its prime
//devanshjsr
