package sample;

import java.io.File;
import java.io.FileNotFoundException;

import org.junit.Test;

public class SortTest {

	@Test
	public void test1() {
		Integer[] array={2,1};
		Sort<Integer> sort= new Sort<Integer>(array);
		sort.QuickSort(0, array.length);
		sort.printArray();
	}
	@Test
	public void test2() {
		Integer[] array={2,123,12};
		Sort<Integer> sort= new Sort<Integer>(array);
		sort.QuickSort(0, array.length);
		sort.printArray();
	}
	@Test
	public void test3() {
		Integer[] array={1,2,1,1};
		Sort<Integer> sort= new Sort<Integer>(array);
		sort.QuickSort(0, array.length);
		sort.printArray();
	}
	@Test
	public void test4(){
		String[] array={"abc","acb","a","z","abcd","b","pqer","gautam","vibhor","Anirudh","Maxim","Dana","Nacho"};
		Sort<String> sort= new Sort<String>(array);
		sort.QuickSort(0, array.length);
		sort.printArray();
		
	}
	@Test
	public void test5(){
		String filename="/Users/gautambajaj/Documents/workspace/example.softbank/src/sample/tempFile";
		File file=new File(filename);
		try {
			Sort<String> sort=new Sort<String>(file);
			sort.QuickSort(0, 35);
			sort.printArray();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	@Test
	public void test6(){
		Integer[] array={3,2,1,3,2,2,1,1,2,3,2,2,3,1,2,3,2};
		Sort<Integer> sort= new Sort<Integer>(array);
		sort.MergeSort(0, array.length);
		sort.printArray();
	}
}
