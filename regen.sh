./generate.sh
cd src
rm zmailer_msg.c
gsl -q -trace:1 zmailer_msg.xml
rm zmailer_server.c
gsl -q -trace:1 zmailer_server.xml
rm zmailer_client.c
gsl -q -trace:1 zmailer_client.xml
cd ..
./autogen.sh
./configure
make
