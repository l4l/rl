nohup java -cp $CLASSPATH:lib/*:* org.LoginServer /tmp 2>>errors 1>>out & echo $$ > pid
