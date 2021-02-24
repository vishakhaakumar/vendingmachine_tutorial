package com.application;

import com.thrift.BeverageType;
import com.thrift.BeveragePreferenceService;

import org.apache.thrift.server.TServer;
import org.apache.thrift.server.TSimpleServer;
import org.apache.thrift.transport.TServerSocket;
import org.apache.thrift.transport.TServerTransport;
import org.apache.thrift.transport.TTransportException;

public class BeveragePreferenceServer {

    private TServer server;

    public void start() throws TTransportException {
        TServerTransport serverTransport = new TServerSocket(9095);
        server = new TSimpleServer(new TServer.Args(serverTransport)
            .processor(new BeveragePreferenceService.Processor<>(new BeveragePreferenceServiceImpl())));

        System.out.print("Starting the server beverage... ");

        server.serve();

        System.out.println("done.");
    }

    public void stop() {
        if (server != null && server.isServing()) {
            System.out.print("Stopping the server... ");

            server.stop();

            System.out.println("done.");
        }
    }
}
