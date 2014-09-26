package sample;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Sort<T extends Comparable<T>> {
	
	T[] array;
	File file;
	
	public Sort(T[] array){
		this.array=array;
	}
	
	public Sort(File file) throws FileNotFoundException{
		Scanner fileScanner=new Scanner(file);
		List<T> l=new LinkedList<T>();
		while(fileScanner.hasNext()){
			l.add((T) fileScanner.next());
		}
		this.array=(T[]) new String[l.size()];
		l.toArray(this.array);
	}
	
	public T[] getArray(){
		return this.array;
	}

	
	public void printArray(){
		for(Integer i=0;i<this.array.length;i++){
			System.out.print(this.array[i]+ " ");
		}
		System.out.println();
	}
	
	public void QuickSort(int start, int end){
		if(end-start<=1)
			return;
		int pivot=end-1;
		int left=start;
		int right=pivot-1;
		while(left<right){
			int compareLeft=this.array[left].compareTo(this.array[pivot]);
			while( compareLeft<=0 && left<right){
				left++;
				compareLeft=this.array[left].compareTo(this.array[pivot]);
			}
			int compareRight=this.array[right].compareTo(this.array[pivot]);
			while(compareRight>=0 && left<right){
				right--;
				compareRight=this.array[right].compareTo(this.array[pivot]);
			}
			T temp = this.array[left];
			this.array[left]=this.array[right];
			this.array[right]=temp;
		}
		int comparePivot=this.array[right].compareTo(this.array[pivot]);
		if(comparePivot>0){
			T temp = this.array[right];
			this.array[right]=this.array[pivot];
			this.array[pivot]=temp;
			pivot=right;
		}
		else{
			T temp = this.array[right+1];
			this.array[right+1]=this.array[pivot];
			this.array[pivot]=temp;
			pivot=right+1;
		}
		QuickSort(start,pivot);
		QuickSort(pivot,end);
	}
	
	private void Merge(int start,int mid, int end){
		int pointer1=0;
		int pointer2=0;
		T[] left=(T[])new Integer[mid-start];
		T[] right=(T[]) new Integer[end-mid];
		for(int i=start;i<mid;i++){
			left[pointer1]=this.array[i];
			pointer1++;
		}
		for(int i=mid;i<end;i++){
			right[pointer2]=this.array[i];
			pointer2++;
		}
		int p=0,q=0;
		for(int j=start;j<end;j++){
	//		System.out.println("j="+j+" p="+p+ " q="+q+" left=" + left[p]+ " right="+right[q]);
			if(p<pointer1 && q<pointer2 && left[p].compareTo(right[q])<0){
				this.array[j]=left[p];
				p++;
			}
			else if(p<pointer1 && q<pointer2){
				this.array[j]=right[q];
				q++;
			}
			else if(p>=pointer1 && q<pointer2){
				this.array[j]=right[q];
				q++;
			}
			else if(q>=pointer2 && p<pointer1){
				this.array[j]=left[p];
				p++;
			}
		}
	}
	
	public void MergeSort(int start,int end){
		if(end-start<=1)
			return;
		int mid=(end+start)/2;
		MergeSort(start, mid);
		MergeSort(mid,end);
		Merge(start,mid,end);
	}
}
