#!/bin/bash
#pulls enum values from mysql table into quoted comma separated list for sql query
hostname=host1
dbname=db1
tablename=table1
user=root
pass=changeme1
column=tobeenumcolumn

echo "retrieving enums..."
uniq=`echo "select $column from \\\`$tablename\\\` group by $column"|mysql -h "$hostname" -u"$user" -p"$pass" "$dbname"|awk '{ if ( NR > 1  ) {printf "\""$1"\","}}'|head --bytes -1`

query="alter table \`$tablename\` modify $column enum("
query+="$uniq"
query+=");"

echo "$query" > /tmp/query.log

echo "updating column..."


echo "$query"|mysql -h "$hostname" -u"$user" -p"$pass" "$dbname"

echo "complete."
