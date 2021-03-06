#!/bin/sh
## ======================================================================

##-----------------------------------------------------------------------
##                        NOTICE!!
## Before using this script to run feature tests, you should
## 0. source greenplum_path.sh
## 1. start HDFS and HAWQ, and create a "gptest" database
## 2. if you HAWQ are not running at localhost:5432, specify PG_BASE_ADDRESS and PG_BASE_PORT
## 3. make sure HADOOP_HOME points to right place and hadoop commands have been added to PATH
## 4. mvn clean package to generate jar files needed
##
## This script must be run in hawq-mapreduce-tool folder!
##-----------------------------------------------------------------------

##
## List of default test cases to run.  This can be overwritten with
## the FEATURE_TEST_LIST environment variable.
##

FEATURE_TEST_LIST=${FEATURE_TEST_LIST:=com.pivotal.hawq.mapreduce.ft.HAWQInputFormatFeatureTest_AO_Compression \
                                       com.pivotal.hawq.mapreduce.ft.HAWQInputFormatFeatureTest_AO_Misc \
                                       com.pivotal.hawq.mapreduce.ft.HAWQInputFormatFeatureTest_AO_Options \
                                       com.pivotal.hawq.mapreduce.ft.HAWQInputFormatFeatureTest_AO_Types \
                                       com.pivotal.hawq.mapreduce.ft.HAWQInputFormatFeatureTest_Parquet_Compression \
                                       com.pivotal.hawq.mapreduce.ft.HAWQInputFormatFeatureTest_Parquet_Misc \
                                       com.pivotal.hawq.mapreduce.ft.HAWQInputFormatFeatureTest_Parquet_Options \
                                       com.pivotal.hawq.mapreduce.ft.HAWQInputFormatFeatureTest_Parquet_Types \
                                       com.pivotal.hawq.mapreduce.ft.HAWQInputFormatFeatureTest_TPCH \
                                       com.pivotal.hawq.mapreduce.ft.HAWQInputFormatFeatureTest_Misc }

##
## Bring in hadoop config environment.
##

source $HADOOP_HOME/libexec/hadoop-config.sh


##
## Clean up any previous tmp working directory and copy contents to
## remote systems.
##

LIBS=(`find .. -name "*.jar" | grep -v javadoc.jar`)
CLASSPATH=$(IFS=:; echo "${LIBS[*]}"):$CLASSPATH

for test in ${FEATURE_TEST_LIST}; do
    command="java -cp $CLASSPATH org.junit.runner.JUnitCore ${test}"

    echo ""
    echo "======================================================================"
    echo "Timestamp ..... : $(date)"
    echo "Running test .. : ${test}"
    echo "command ....... : ${command}"
    echo "----------------------------------------------------------------------"

    ${command} | tee -a inputformat.logs 2>&1

    echo "======================================================================"
    echo ""
done

##
## Generate reports parsed by pulse.
##
python generate_mr_report.py 
