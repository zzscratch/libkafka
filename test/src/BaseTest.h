#include <string>
#include <gtest/gtest.h>
#include <Debug.h>
#include <Broker.h>
#include <TopicMetadata.h>
#include <PartitionMetadata.h>
#include <MetadataRequest.h>
#include <MetadataResponse.h>
#include <Message.h>
#include <ApiConstants.h>

using namespace std;
using namespace LibKafka;

class BaseTest : public ::testing::Test {
  protected:

    BaseTest();
    virtual ~BaseTest();
    virtual void SetUp();
    virtual void TearDown();

    // Broker
    const static int nodeId = 2;
    const static int port = 8000;
    Broker *createBroker(string host = string("test_host"));

    // PartitionMetadata
    const static short int partitionErrorCode = 2;
    const static int leader = 2;
    const static int replicaArraySize = 3;
    const static int isrArraySize = 3;
    static int *replicaArray;
    static int *isrArray;
    PartitionMetadata *createPartitionMetadata(int partitionId = 9);

    // TopicMetadata
    const static short int topicErrorCode = 6;
    const static int partitionMetadataArraySize = 3;
    static PartitionMetadata **partitionMetadataArray;
    TopicMetadata *createTopicMetadata(string topicName = string("test_topic"));

    // MetadataResponse
    const static int correlationId = 212121;
    const static int brokerArraySize = 3;
    const static int topicMetadataArraySize = 2;
    static Broker **brokerArray;
    static TopicMetadata **topicMetadataArray;
    MetadataResponse *createMetadataResponse();

    // MetadataRequest
    const static short int apiKey = ApiConstants::METADATA_REQUEST_KEY;
    const static short int apiVersion = ApiConstants::API_VERSION;
    const static string clientId;
    const static int topicNameArraySize = 3;
    static string *topicNameArray;
    MetadataRequest *createMetadataRequest(bool emptyTopicArray = false);

    // Message
    const static long int offset = 21;
    const static int crc = 1001;
    const static signed char magicByte = -1;
    const static signed char attributes = -2;
    const static int keyLength = 10;
    static unsigned char *key;
    const static int valueLength = 20;
    static unsigned char *value;
    Message *createMessage();
};
