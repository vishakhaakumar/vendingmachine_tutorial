package BeveragePreferenceService;

import org.apache.thrift.transport.TTransportException;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import com.application.BeveragePreferenceServer;

@SpringBootApplication
public class BeveragePreferenceServiceApplication {

	public static void main(String[] args) {
		System.out.println("Bev server ");
		BeveragePreferenceServer server = new BeveragePreferenceServer();
        try {
			server.start();
		} catch (TTransportException e) {
			e.printStackTrace();
		}
	}

}
