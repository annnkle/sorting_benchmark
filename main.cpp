#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <fstream>

using namespace std;

void array_duplication(int*, int*, int);
void generator(int*, int*, int*, int*, int*, int);

void max_heap_repair(int*, int, int);
void build_max_heap( int*, long long);
void heap_sort( int*, int );
void shell_sort(int*, int);
void insertion_sort(int*, int);
void quicksort_random(int*, int, int);
int random_partitionq(int*, int, int);
void selection(int*, int);
void quicksort(int*, int, int);
int partitionq(int*, int, int);
int main()
{

	int n;
	cout<<"Enter number of elements to be sorted: "<<endl;
	cin >> n;

	int asc[n];
	int desc[n];
	int con[n];
	int A[n];
	int randm[n];

    int asc2[n];
	int desc2[n];
	int con2[n];
	int A2[n];
	int randm2[n];


	generator(asc, desc, con, A, randm, n);

	//create backups of number sequences


	array_duplication(asc, asc2, n);
	array_duplication(desc, desc2, n);
	array_duplication(con, con2, n);
	array_duplication(A, A2, n);
	array_duplication(randm, randm2, n);


    string filename;
    ofstream file;
    cout<<"Enter filename for output: "<<endl;
    cin>>filename;
    file.open(filename.c_str());


	file<<"Sorting algorithms benchmark for "<<n<< " elements\n"<<endl;
	file<<"Ascending sequence:"<<endl;

    clock_t begin = clock();
    selection(asc, n);
	clock_t end = clock();
    file<<"Selection sort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(asc2, asc, n);

    begin = clock();
    insertion_sort(asc, n);
    end = clock();
    file<<"Insertion sort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(asc2, asc, n);

    begin = clock();
    heap_sort(asc, n-1);
    end = clock();
    file<<"Heap sort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(asc2, asc, n);

    begin = clock();
    quicksort(asc, 0, n-1);
    end = clock();
    file<<"Quicksort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(asc2, asc, n);

    begin = clock();
    quicksort_random(asc, 0, n-1);
	end = clock();
    file<<"Random quicksort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(asc2, asc, n);

    begin = clock();
    shell_sort(asc, n);
	end = clock();
    file<<"Shellsort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;


    file<<"\nDescending sequence:"<<endl;

    begin = clock();
    selection(desc, n);
    end = clock();
    file<<"Selection sort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(desc2, desc, n);

    begin = clock();
    insertion_sort(desc, n);
    end = clock();
    file<<"Insertion sort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(desc2, desc, n);

    begin = clock();
    heap_sort(desc, n-1);
    end = clock();
    file<<"Heap sort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;
    array_duplication(desc2, desc, n);

    begin = clock();
    quicksort(desc, 0, n-1);
    end = clock();
    file<<"Quicksort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(desc2, desc, n);

    begin = clock();
    quicksort_random(desc, 0, n-1);
	end = clock();
    file<<"Random quicksort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(desc2, desc, n);

    begin = clock();
    shell_sort(desc, n);
	end = clock();
    file<<"Shellsort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;




    file<<"\nConstant sequence:"<<endl;

    begin = clock();
    selection(con, n);
    end = clock();
    file<<"Selection sort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(con2, con, n);

    begin = clock();
    insertion_sort(con, n);
    end = clock();
    file<<"Insertion sort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(con2, con, n);

    begin = clock();
    heap_sort(con, n-1);
    end = clock();
    file<<"Heap sort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(con2, con, n);

    begin = clock();
    quicksort(con, 0, n-1);
    end = clock();
    file<<"Quicksort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(con2, con, n);

    begin = clock();
    quicksort_random(con, 0, n-1);
	end = clock();
    file<<"Random quicksort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(con2, con, n);

    begin = clock();
    shell_sort(con, n);
	end = clock();
    file<<"Shellsort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;



    file<<"\nA-shaped sequence:"<<endl;

        begin = clock();
    selection(A, n);
    end = clock();
    file<<"Selection sort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(A2, A, n);

    begin = clock();
    insertion_sort(A, n);
    end = clock();
    file<<"Insertion sort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(A2, A, n);

    begin = clock();
    heap_sort(A, n-1);
    end = clock();
    file<<"Heap sort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(A2, A, n);

    begin = clock();
    quicksort(A, 0, n-1);
    end = clock();
    file<<"Quicksort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(A2, A, n);

    begin = clock();
    quicksort_random(A, 0, n-1);
	end = clock();
    file<<"Random quicksort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(A2, A, n);

    begin = clock();
    shell_sort(A, n);
	end = clock();
    file<<"Shellsort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;





    file<<"\nRandom sequence:"<<endl;

    begin = clock();
    selection(randm, n);
    end = clock();
    file<<"Selection sort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(randm2, randm, n);

    begin = clock();
    insertion_sort(randm, n);
    end = clock();
    file<<"Insertion sort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(randm2, randm, n);

    begin = clock();
    heap_sort(randm, n-1);
    end = clock();
    file<<"Heap sort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(randm2, randm, n);

    begin = clock();
    quicksort(randm, 0, n-1);
    end = clock();
    file<<"Quicksort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(randm2, randm, n);

    begin = clock();
    quicksort_random(randm, 0, n-1);
	end = clock();
    file<<"Random quicksort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    array_duplication(randm2, randm, n);

    begin = clock();
    shell_sort(randm, n);
	end = clock();
    file<<"Shellsort: "<< (float)(end - begin) / CLOCKS_PER_SEC << " seconds"<<endl;

    file.close();


	return 0;
}


void generator(int *asc, int *desc, int *con, int *A, int *randm, int n){

	int i, gen, BIG;
	time_t t;

	srand((unsigned) time(&t));
	//ascending number sequence
	for(i = 0; i < n; i++){

    	gen = (rand()%11);
    	if(i == 0)
        	asc[i] = gen;
    	else
        	asc[i] = asc[i-1] + gen;

	}
	
	//descending number sequence
	for(i = 0; i < n; i++){
    	BIG = (rand()%10001);
    	gen = (rand()%11);
    	if (i == 0)
        	desc[i] = BIG;
    	else
        	desc[i] = desc[i - 1] - gen;
	}
	
	//constant
	for(i = 0; i < n; i++){
    	if (i == 0)
        	gen = (rand()%101);

    	con[i] = gen;
	}
	
	//A-shaped
	for(i = 0; i < n; i++){
    	gen = (rand()%11);
    	if(i == 0)
        	A[i] = gen;
    	if(i > 0 && i <= n/2)
        	A[i] = A[i-1] + gen;
    	if(i > n/2)
        	A[i] = A[i-1] - gen;

	}
	
	//rAnDoM
	for(i = 0; i < n; i++){
    	gen = (rand()%100);
    	randm[i] = gen;
	}
}


void selection(int *table, int n){

	int store, tmp, index;

	for (int i = 0; i < n-1; i++){
			store = table[i];
			tmp = store;
			index = i;
			for(int j = i; j < n; j++){
				if(store > table[j]){
					store = table[j];
					index = j;
				}
			}
			table[index] = tmp;
			table[i] = store;
	}
}


void quicksort(int *table, int m, int n){

	if(m < n){
		int q = partitionq(table, m, n);
		quicksort(table, m, q-1);
		quicksort(table, q+1, n);
	}
}


int partitionq(int *table, int m, int n){

	int pivot = table[n];
	int index = m-1;
	for(int i = m; i <= n-1; i++){
		if(table[i] <= pivot){
			index++;
			swap(table[index], table[i]);
		}
	}
	swap(table[index+1], table[n]);

	return index + 1;
}


void quicksort_random(int *table, int m, int n){

	if(m<n){
		int q = random_partitionq(table, m, n);
		quicksort_random(table, m, q-1);
		quicksort_random(table, q+1, n);
	}

}


int random_partitionq(int *table, int m, int n){

	int index_pivot = (rand()%n+1);
	if(index_pivot < m){
		index_pivot += (m - index_pivot);
	}
	swap(table[index_pivot], table[n]);
	int q = partitionq(table, m, n);

	return q;
}

void max_heap_repair( int* table, int len, int i )
{
	int BIG = i;
	int left =  2*i + 1;
	int right = 2*i + 2;
	if( (left <= len) ){
    	if( table[left] > table[i] ){
        	BIG = left;
    	}
    	else{
        	BIG = i;
    	}
	}
	if( right <= len ){
    	if( table[right] > table[BIG] ){
        	BIG = right;
    	}
	}

	if( BIG != i ){
    	swap(table[i], table[BIG]);
    	max_heap_repair( table, len, BIG );
	}
}


void build_max_heap( int*table , int len )
{
	for( int i = ceil(len / 2)-1; i >= 0; i -- )
	{
    	max_heap_repair( table, len, i );
	}
}


void heap_sort( int*table, int len )
{
	build_max_heap( table, len );
	for( int i = len; i > 0; i --  ){
    	swap( table[0], table[i] );
    	max_heap_repair( table, i - 1, 0 );
	}
}


void insertion_sort(int *table, int n){
   int i, key, j;
   for (i = 1; i < n; i++){
       key = table[i];
       j = i-1;
       while (j >= 0 && table[j] > key)
       {
           table[j+1] = table[j];
           j = j-1;
       }
        table[j+1] = key;
   }
}


void shell_sort(int *table, int n){
    int gap, i, j;
    for ( gap = n/2; gap > 0; gap /= 2) {
            for ( i = gap; i < n; i += 1) {
                    int temp = table[i];
                    for (j = i; j >= gap && table[j - gap] > temp; j -= gap){
                        table[j] = table[j - gap];
                    }
                    table[j] = temp;
            }
    }
}


void array_duplication(int *ar1, int *ar2, int len){

	for(int i = 0; i < len; i++){
		ar2[i] = ar1[i];
	}
}
