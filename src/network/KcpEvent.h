#pragma once

class KcpSession;
class UdpPacket;
class KcpEvent
{
public:
	KcpEvent();
	virtual ~KcpEvent();

	virtual KcpSession * createConnect();
	virtual void destroyConnect(KcpSession * conn);

	virtual void onUdpTimeout(KcpSession * ){};  //���ӳ�ʱ������close�ûỰ
	virtual void onAccept(KcpSession * conn){};
	virtual void onConnect(KcpSession * conn){};
	virtual void onClose(KcpSession * conn){};
	virtual void onMsg(KcpSession * conn, UdpPacket * pack){};
};