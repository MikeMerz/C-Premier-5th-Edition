//Exercise 12.15: Rewrite the first exercise to use a lambda (§ 10.3.2, p.
//388) in place of the end_connection function.


#include <memory>
#include <ostream>
#include <iostream>

struct connection
{
    std::string ip;
    int port;
    bool isConnected;
    connection(const std::string& _ip, int _port):ip(_ip),port(_port),isConnected(false){}
};
struct destination
{
    std::string ip;
    int port;
    destination(const std::string& _ip, int _port):ip(_ip),port(_port){}
};

connection connect(destination& d)
{
    std::shared_ptr<connection> conn(std::make_shared<connection>(d.ip,d.port));
    conn->isConnected = true;
    return *conn;
}
void disconnect(connection conn)
{
    conn.isConnected = false;
    std::cout <<"closed"<<std::endl;
}
void end_connection(connection* conn)
{
    disconnect(*conn);
}
void func(destination &d)
{
    connection c = connect(d);
    std::shared_ptr<connection> p(&c, [&](auto conn){
        disconnect(*conn);
    });
}
int main()
{
    destination dest("10.10.10.10",10);
    func(dest);
    return 0;
}

