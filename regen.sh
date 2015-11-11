./generate.sh
cd src
gsl -q -trace:1 zmailer_msg.xml
gsl -q -trace:1 zmailer_server.xml
gsl -q -trace:1 zmailer_client.xml
cd ..
./autogen.sh
./configure
make
