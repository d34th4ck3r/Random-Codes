package sample;

import static org.junit.Assert.*;

import org.junit.Test;

public class HelloWorldTest {

	@Test
	public void main() {
		HelloWorld hw= new HelloWorld();
		String[] args={};
		hw.main(args);
		System.out.println("This is from test");
	}

}
