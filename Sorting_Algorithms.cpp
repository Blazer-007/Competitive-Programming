#include<bits/stdc++.h>
using namespace std;

void printArray(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"\n";
}

void printArray2(vector <int> & arr)  
{  
    for (int i=0; i < arr.size(); i++)  
        cout << arr[i] << " ";  
    cout << "\n";  
} 


// Bubble Sort

void bubble_Sort(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n-1;j++){
			if(a[j]<a[i]){
				swap(a[i],a[j]);
			}
		}
	}
}

// Selection Sort

void selection_Sort(int a[],int n){
	
	for(int i=0;i<n-1;i++){
		int min_Index=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min_Index]){
				min_Index = j;
			}
		}
		swap(a[i],a[min_Index]);
	}
}

// Insertion Sort

void insertion_Sort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}

// Wave Sort ( array in wave form)

void wave_Sort(int a[],int n){
	for(int i=0;i<n;i+=2){
		
		// Checking with left element 
		if(i>0 && a[i]<a[i-1])
		swap(a[i],a[i-1]);
		
		// Checking with right element
		if(i<n-1 && a[i]<a[i+1])
		swap(a[i],a[i+1]);
	}
}

// Counting Sort (logic - restore the frequency of all elements of array , then iterate over freq array and make new array a/c to its freq )

void count_Sort(vector <int>& arr) 
{ 
    int max = *max_element(arr.begin(), arr.end()); 
    int min = *min_element(arr.begin(), arr.end()); 
    int range = max - min + 1; 
      
    vector<int> count(range), output(arr.size()); 
    for(int i = 0; i < arr.size(); i++) 
        count[arr[i]-min]++; 
          
    for(int i = 1; i < count.size(); i++) 
           count[i] += count[i-1]; 
    
    for(int i = arr.size()-1; i >= 0; i--) 
    {  
         output[ count[arr[i]-min] -1 ] = arr[i];  
              count[arr[i]-min]--;  
    } 
      
    for(int i=0; i < arr.size(); i++) 
            arr[i] = output[i]; 
} 

// Quick Sort (Randomized , using fn shuffle we shuffle elements so that if sorted aaray comes , it becomes unsorted)

void shuffle(int a[],int s,int e){
	int i,j;
	srand(time(NULL));
	
	for(i=e;i>0;i--){
		j = rand()%(i+1);
		swap(a[i],a[j]);
	}
}

int partition(int a[],int s,int e){
	int i=s-1;
	int j=s;
	
	for(;j<e;j++){
		if(a[j]<a[e]){
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[e]);
	return i+1;
}

void quick_Sort(int a[],int s,int e){
	if(s>=e)
	return ;
	
	int p = partition(a,s,e);
	
	quick_Sort(a,s,p-1);
	quick_Sort(a,p+1,e);
}


// Merge Sort

void merge(int a[],int s,int e){
    int mid = (s+e)/2;
	int i=s;
	int j=mid+1;
	int temp[100];
	int k=s;
	while(i<=mid&&j<=e){
		if(a[i]<a[j]){
			temp[k++] = a[i++];
		}else{
			temp[k++] = a[j++];
		}
	}
	while(i<=mid){
		temp[k++]=a[i++];
	}
	while(j<=e){
		temp[k++]=a[j++];
	}
	
	for(int i=s;i<=e;i++){
		a[i]=temp[i];
	}//cout<<"\n";
}

void merge_Sort(int a[],int s,int e){
	if(s>=e)
	return ;
	
	int mid = (s+e)/2;
	
	merge_Sort(a,s,mid);
	merge_Sort(a,mid+1,e);
	
	merge(a,s,e);
}


// Bucket Sort ( mainly used for floating numbers )

void bucket_Sort(float arr[], int n) 
{ 
    // 1) Create n empty buckets 
    vector<float> b[n]; 
     
    // 2) Put array elements in different buckets 
    for (int i=0; i<n; i++) 
    { 
       int bi = n*arr[i]; // Index in bucket 
       b[bi].push_back(arr[i]); 
    } 
  
    // 3) Sort individual buckets 
    for (int i=0; i<n; i++) 
       sort(b[i].begin(), b[i].end()); 
  
    // 4) Concatenate all buckets into arr[] 
    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < b[i].size(); j++) 
          arr[index++] = b[i][j]; 
} 

// Shell Sort

int shellSort(int arr[], int n) 
{ 
    // Start with a big gap, then reduce the gap 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted  
        for (int i = gap; i < n; i += 1) 
        { 
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = arr[i]; 
  
            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
              
            //  put temp (the original a[i]) in its correct location 
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 



int main(){
//	int a[] = { 50,23,67,100};
//	int n = 4;
//	bubble_Sort(a,n);
//	printArray(a,n);
//	int b[] = { 2,1,5,8,4};
//	//selection_Sort(b,5);
//	selection_Sort(a,4);
//	//printArray(b,5);
//	printArray(a,n);
//	insertion_Sort(a,n);
//	printArray(a,n);
//	wave_Sort(a,n);
//	printArray(a,n);
//	vector<int> arr = {-5, -10, 0, -3, 8, 5, -1, 10}; 
//    count_Sort (arr); 
//    printArray2(arr); 
//    quick_Sort(b,0,4);
//    shuffle(b,0,4);
//	printArray(b,5);
//	quick_Sort(b,0,4);
//	printArray(b,5); 

//    int v[] ={99,85,96,51,-1,0};
//    merge_Sort(v,0,5);
//    printArray(v,6);

//    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434}; 
//    int n = sizeof(arr)/sizeof(arr[0]); 
//    bucket_Sort(arr, n); 
//    printArray(arr,n);

	return 0;
}
