#include <stdio.h>
#include <stdlib.h>


#include "NetEvent.h"
#include "EventLoop.h"
#include "NetClient.h"
#include "NetServer.h"
#include "Timer.h"
#include "NetConnect.h"
#include "NetPacket.h"
#include "TcpPacketFactory.h"

class INetEvent : public NetEvent
{
public:
	virtual void onAccept(NetConnect * conn){
		if (conn)
		{
			conn->sendMsg(1, "12345\0", 6);
		}
	};

	virtual void onConnect(NetConnect * conn){
		if (conn)
		{
			
		}
	};
	virtual void onClose(NetConnect * conn){
		
	};

	virtual void onMsg(NetConnect * conn, NetPacket * pack){
		std::string s;
		(*pack) >> s;

		printf("%s\n", s.c_str());
		conn->sendMsg(1, pack);
	}
};

//#define CLIENT_TEST

int main()
{
	//��ʼ��tcp���ڴ��
	tcpPacketFactory = new TPacketFactory();

	//��ʼ���¼�ѭ��
	INetEvent eve;
	EventLoop::Instance()->init();

#ifdef CLIENT_TEST
	NetClient client(EventLoop::Instance(), &eve);
	client.connect("127.0.0.1", 3001);
	
#else
	NetServer server(EventLoop::Instance(), &eve);
	server.listen("127.0.0.1", 3001);

#endif

	//�����¼�ѭ��
	EventLoop::Instance()->Run();

	delete tcpPacketFactory;

	system("pause");
	return 0;
}