#include "zmailer.h" 

int main() {
 zsys_info ("start test case");
 zactor_t *myserver = zactor_new (zmailer_server, NULL);
 //zstr_sendx (myserver, "BIND", "ipc://@/zmailer_server", NULL);
 zstr_sendx (myserver, "BIND", "tcp://127.0.0.1:9999", NULL);
 sleep (60);
 zsys_info ("completed");
 zactor_destroy (&myserver);
 return 0;
}
