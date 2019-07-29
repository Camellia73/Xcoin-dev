// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>

namespace CryptoNote {
namespace parameters {

const uint32_t HF_APR18_HEIGHT                               = 1; // offset by one! actually 70913

const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 7237;
const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW         = 50;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 500;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;

// MONEY_SUPPLY - total number coins to be generated
const uint64_t MONEY_SUPPLY                                  = UINT64_C(2100000000000000);
const unsigned EMISSION_SPEED_FACTOR                         = 21;
const uint64_t GENESIS_BLOCK_REWARD                          = UINT64_C(42);
const uint64_t SECOND_BLOCK_REWARD                           = UINT64_C(840000000000000);
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 350000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V3  = 20000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 20000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 10000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
const uint64_t MINIMUM_FEE                                   = UINT64_C(100000);
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(100000);

const uint64_t DIFFICULTY_TARGET                             = 120; // seconds
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   LEGACY_DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   LEGACY_DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   LEGACY_DIFFICULTY_LAG                                = 15;  // !!!
const size_t   LWMA_DIFFICULTY_WINDOW                             = 60; // blocks
const size_t   LWMA_DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting - not used atm
const size_t   LWMA_DIFFICULTY_LAG                                = 0;  // !!!
static_assert(2 * LEGACY_DIFFICULTY_CUT <= LEGACY_DIFFICULTY_WINDOW - 2, "Bad LEGACY_DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        = 20 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = MAX_BLOCK_SIZE_INITIAL * 75 / 100;  // was: CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t KEY_IMAGE_CHECKING_BLOCK_INDEX                = 0;
const uint32_t UPGRADE_HEIGHT_V2                                = 1;
const uint32_t UPGRADE_HEIGHT_V3                                = 2;
const uint32_t UPGRADE_HEIGHT_V4                                = HF_APR18_HEIGHT;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.bin";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.bin";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "Xcoin";

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  CURRENT_TRANSACTION_VERSION                   =  TRANSACTION_VERSION_1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  20000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  200;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  2000;

const int      P2P_DEFAULT_PORT                              =  28688;
const int      RPC_DEFAULT_PORT                              =  28689;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 128 * 1024 * 1024; // 128 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 12;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 100000000;      // 100000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "";

const char* const SEED_NODES[] = { "communitypool.org:28688", "xvv.communitypool.org:28688", "192.95.20.54:28688", "144.217.29.36:28688" };


struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {
	  {1, "abdbc7c33d9be1f06ae4e1987246625b1f6e46b99820e4693baa7f395b4a8edf"},
	  {100, "2eacadb21b2773834d24a5440e17c57a746e2898e20445340d9a1fb49c9bfc82"},
	  {1000, "ac9a2aa114b1ceea5ac5538d275bef2c3ac191e95bff68a149546f9c075564d6"},
	  {10000, "07f9dc9440a70784a197a3a57b2eb7063d0ebae1117107a33f38b532c8df52a1"},
	  {10400, "6cca7d1d494f44651943f1c64e587fff764aec577dae213e4692a1c197dd0951"},
	  {10401, "dd6f5af98f552b4d202b5ffee21898cc87c0c71263d7b9fd8e7496467295f4df"},
	  {10430, "e021982aab406fe945773f88180afff1509b14866973dac295a5bebea1750343"},
	  {11065, "c8f542981f0c00ff8fd3e141b9c7e3202fb184c40256d9b0c5b3161c76cb388f"},
	  {11066, "54f3637dc8c9f0f368dc069d37f85898caf9bca2939159fcc70cb849865a038c"},
	  {11392, "21c3e854191b03a08a6b642d733bb4ded5d2a79e87f7891ff99281060741f608"},
	  {11548, "73f9378b013c646f645cd7aa5a7365c21ad4c20b1e03c12598ade3868963dcbf"},
	  {11558, "dde83fc1a1e08ee055172e832a54042134ba76d093bfc3b60385d012a1cdca0c"},
	  {11738, "e0efa49de4b49d80797d64123b03d9058cbcea604f89bf191d8f66969f6df2f7"},
	  {11955, "af533184dcce7eb59c302612d625bf84463baa4bbc5b011ab6e998890dd1ca32"},
	  {12043, "6f9918bf51b084188fc81ebeedce4765421ab80043f8a714ee09745094006c26"},
	  {12510, "296fcfb9e6757a9da4ad7cc9ab00265cde927e75d816e01f3b2bd65bb08c849b"},
	  {14219, "9059e0cff2ba719d090866815f49cc9eab549acfdfafa75257ffc887016b9a72"},
	  {15235, "749f17221c0eec3fecbe05e4d2efd9790520b206b8a7d33978252ac94d581216"},
	  {16747, "5fdfb1412c3e65ab97e874d805fea0457992b185942ace7a19a0afa4e5233ed9"},
	  {21984, "33ad380d7d7ff9955c0aea587ceb7d2e060da207e1fed6955fcbc0a2175d2afa"},
	  {22176, "ed9671b7f0a1ddceef9f214340c7021f6c2af589cd4ca886acd83d09aab9c929"},
	  {23320, "e7ee453818bab19a7f805fef30487fa15871ebde09ab800f2540434ad34c2ca9"},
	  {23321, "016f19d6237efe13cdcf9717fbc64912d0e8ac46bd855476f456d48fde50331e"},
	  {23322, "4357f7a27db9c4a4c765dcaeb21c2dda757b8b0fc9439728685b12b70d3da4b3"},
	  {23323, "2c58ae791589607c4bb20888d37bd5d0cce2408b30bc30c2f43a70ab94f2cc19"},
	  {23324, "e4eadf532a5cf12446697d3933561edf102e5841f7dfa9bcfd32eb0c6a02325c"},
	  {23325, "9e2ed0942cbb2e03d6a30c51097c80a5ff3591689dabf1515fa7a7551d2da8ad"},
	  {23326, "2938dba985fd30d1049e312792b75ab26359901d09fe7e04247c4f697222795d"},
	  {23327, "29a7fcc91d4611dce0b3170c0c350de98ffeef4702ecf72cd7bc44e43c4e6426"},
	  {23328, "99cc46c8b903e66f27c193b3a6a112c206a3691043a1992f008037073ce6453f"},
	  {23329, "f666daac014a4595e42ad4b4d938fde4419c6fb6bdc5858347403373fbbca4cc"},
	  {23330, "f43649adf6b101296ffca8616f8260d31abf0fb5f0ffa6fd66f49e9b01beab0c"},
	  {23331, "adbedf6ae36fcfe4ad20520570424f422a58de9d3c768bdbac037145bd2b593e"},
	  {23332, "a6b6627cff48c9a9da0b0ecbe686db559ff8910eebe20918f72fe55aee2ea765"},
	  {23333, "df8f16bc7b5d6704cd97ecfdd0e6a4f1417c4d8b503d351ce58c5586dad2996c"},
	  {23334, "557bb1b72caaa05fc414e17f6bcd50768271b31b20f615b4edab32482ac660de"},
	  {23335, "8d213f2849b301f0316645910be19654171530f7c82d1376d2293a6668f84689"},
	  {23336, "cef11dea23112e03c4bec1105161e9c0e027d90d187feb56a0a1295033742d2e"},
	  {25072, "2052a8ff15345c659f2aea21886e4dcbdf0a250e0e3f7852ca69b44c2931b005"},
	  {25571, "4b8bec0a31c971686be084cc8a6d129e24d5c75f596c793708b262bd569b3128"},
	  {25875, "58b7a7aea211d11219b5d6400f8d5dfa312c0e579eb436dcb4570e4ba17d5fa0"},
	  {26068, "51561b1da726338a8234661e31c417d7d7a925ef55053261af944c539fded06e"},
	  {26252, "30fec2940bd4a03004cef9817bb501b394c95677289434eecc4c9ac8f51e6c67"},
	  {27585, "4b1f3574c0a992d272f98ce634755054d917711ce610c3de2fdd1af72e509dcc"},
	  {31269, "a1839dec27ba00cbad18431a7bc4f857b5763f2ca017428f6c17e0f1530afab6"},
	  {32695, "121d09bf624caf49e0ad127310f61b8174911f6bb067b09b98477373d09974ad"},
	  {35564, "e2d133cc957411b0995d00e90bc6afe4d7d60ec7743f8e6239e610f4d853f7d9"},
	  {38401, "8cce367b4793000c2ce93a93a168eb9cf1ce9b7d61bfeb483cbb768c92fe0086"},
	  {38944, "fbd956810386599fe6b3a451fa6133cb4baf95039d9628a7af2c1942fb5442fb"},
	  {39288, "0f59960a18af0060b778bd5da2cc12999081d34614e8d34e76c19e1fbd5a6232"},
	  {43944, "08c475fb98e7ec749b983a42ebe99d5c59d0a631b97947e53684ea21889f0465"},
	  {44020, "4303306a390fda121b05a56c14e75c1b22fbc05d8e1eb88764241490f075a1d3"},
	  {45582, "2928df03b65b6bdccf8a9289a30b2268aec417f484dbb7e6171512344f661b6b"},
	  {46262, "5b9a3ee221141fdfbead38298dffa82725ccee783a890e14562dcb5b4a122788"},
	  {46268, "a041e6e8a168f1c3be638c777b37b6c7351668f0d048b397642275bf3db01530"},
	  {46355, "57449c3a83830106e2c63a3d8f005249a766bde3501feff410ca5c6581d6485b"},
	  {47547, "4b4b46d7be8bd50de9800982bbbc0afa2cd92e2e5bdbb1b5680249107eda8ce4"},
	  {50000, "abe389870d55e2837900da6beb0994697a821a4a3756ac6cde94faf7a9c86a4a"},
	  {51000, "2bc37659c40a76c0aeb430c5c13142a5a478eb9e28ca09f40fe5797ffbce9752"},
	  {51240, "8f5169da1c0f89333dd2c9c1f7d6d85527ca9dacde88459703688a5b9e07b4cc"}
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS



