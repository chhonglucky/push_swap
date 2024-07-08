#make
#make bonus
CNT=500
LIMIT=10000
INDEX=0
ITER=100
NUM_OVER=0
MAX=$LIMIT
SUM=0
OK=0
KO=0
OKSIGN=`echo "OK"`
ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
RESULT=`./push_swap $ARG`
NUM=`echo "$RESULT" | wc -l | tr -d " "`
while [ $INDEX -lt $ITER ]
do
PF=`echo "$RESULT" | ./checker $ARG`
echo "$INDEX	:	$NUM	:	$PF"
if [ $PF == $OKSIGN ]
then
	OK=`expr $OK + 1`
else
	KO=`expr $KO + 1`
fi
SUM=`expr $SUM + $NUM`
if [ $NUM -ge $LIMIT ]
then
	NUM_OVER=`expr $NUM_OVER + 1`
fi
if [ $NUM -gt $MAX ]
then
	MAX=$NUM
fi
ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
RESULT=`./push_swap $ARG`
NUM=`echo "$RESULT" | wc -l | tr -d " "`
INDEX=`expr $INDEX + 1`
done
echo "$NUM_OVER overred operations for $ITER times"
if [ $NUM_OVER -gt 0 ]; then
	echo "Biggest operation number : $MAX"
	echo "fix it!!!!!!!!!!"
fi
echo "Avarage : " | tr -d "\n"
echo "$SUM/$ITER" | bc
printf "OK : %s, KO : %s\n" $OK $KO
#make fclean