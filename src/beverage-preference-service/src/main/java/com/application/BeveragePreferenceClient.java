package com.application;

import org.apache.thrift.TException;
import org.apache.thrift.protocol.TBinaryProtocol;
import org.apache.thrift.protocol.TProtocol;
import org.apache.thrift.transport.TSocket;
import org.apache.thrift.transport.TTransport;

import com.thrift.*;

public class BeveragePreferenceClient {
		public static void main(String[] args) throws TException {
			
		    TTransport transport = new TSocket("localhost", 9095);
	        try {
	            transport.open();
	            System.out.println("Inside the Client ----> ");
	            TProtocol protocol = new TBinaryProtocol(transport);
	            BeverageType btype = BeverageType.COLD;
	            BeveragePreferenceService.Client client = new BeveragePreferenceService.Client(protocol);
	            System.out.println("val is  = " + client.getBeverage(btype));
	        }catch(Exception e){
	        	e.printStackTrace();
	        	System.out.println("error in client");
	        }
	        finally {
	            transport.close();
	        }
	    }
}

