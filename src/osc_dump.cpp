#include "ip/IpEndpointName.h"
#include "ip/UdpSocket.h"

#include "osc/OscPacketListener.h"

#include <iostream>

#define BUFF_SIZE 1024

// OSCメッセージ受信クラス
class OscHandler : public osc::OscPacketListener
{
public:
    OscHandler() {}
    ~OscHandler() {}

protected:
    virtual void ProcessMessage(const osc::ReceivedMessage& msg, const IpEndpointName& remote_end_pt) override
    {
        // 送信元アドレス・ポート番号の出力
        std::cout << "Received osc message from \"";
        char addr_and_port[BUFF_SIZE];
        remote_end_pt.AddressAndPortAsString(addr_and_port);
        std::cout << addr_and_port << "\": " << msg.AddressPattern() << std::endl;
    }
};

int main()
{
    int32_t port = 7000;

    OscHandler osc_handler;
    UdpListeningReceiveSocket sock(IpEndpointName(IpEndpointName::ANY_ADDRESS, port), &osc_handler);

    std::cout << "Start listening osc message on port " << port << std::endl;
    sock.RunUntilSigInt();
    std::cout << "Terminate listening" << std::endl;
}
