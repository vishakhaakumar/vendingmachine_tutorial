namespace java com.thrift

enum BeverageType{
	HOT,
	COLD
}

service BeveragePreferenceService{
	string getBeverage(
		1: BeverageType btype
	)
}
