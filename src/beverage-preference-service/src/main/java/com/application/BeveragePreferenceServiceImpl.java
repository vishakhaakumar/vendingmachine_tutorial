package com.application;

import org.apache.thrift.TException;

import com.thrift.BeveragePreferenceService;
import com.thrift.BeverageType;

public class BeveragePreferenceServiceImpl implements BeveragePreferenceService.Iface{

	
	@Override
	public String getBeverage(BeverageType btype) throws TException {
		System.out.println(" city is ------------>>"+btype);
		return "Helloooo";
	}

}
