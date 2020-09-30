//
// Created by lightnet on 2020/9/4.
//

#pragma once

#include <string>
#include <vector>
#include <libdevcore/picosha2.h>


namespace dev
{
/**
 * Encode a byte sequence as a base58-encoded string.
 * pbegin and pend cannot be NULL, unless both are.
 */
std::string encodeBase58(const unsigned char *pbegin, const unsigned char *pend);

/**
 * Encode a byte vector as a base58-encoded string
 */
std::string encodeBase58(const std::vector<unsigned char> &vch);

/**
 * Decode a base58-encoded string (psz) into a byte vector (vchRet).
 * return true if decoding is successful.
 * psz cannot be NULL.
 */
bool decodeBase58(const char *psz, std::vector<unsigned char> &vchRet);

/**
 * Decode a base58-encoded string (str) into a byte vector (vchRet).
 * return true if decoding is successful.
 */
bool decodeBase58(const std::string &str, std::vector<unsigned char> &vchRet);

/**
 * Encode a byte vector into a base58-encoded string, including checksum.
 * pbegin and pend cannot be NULL, unless both are.
 */
std::string encodeBase58Check(const unsigned char *pbegin, const unsigned char *pend);

/**
 * Encode a byte vector into a base58-encoded string, including checksum.
 */
std::string encodeBase58Check(const std::vector<unsigned char> &vchIn);

/**
 * Decode a base58-encoded string (psz) that includes a checksum into a byte
 * vector (vchRet), return true if decoding is successful
 */
bool decodeBase58Check(const char *psz, std::vector<unsigned char> &vchRet);

/**
 * Decode a base58-encoded string (str) that includes a checksum into a byte
 * vector (vchRet), return true if decoding is successful
 */
bool decodeBase58Check(const std::string &str, std::vector<unsigned char> &vchRet);

/**
 * Do sha256 twice
 */
std::vector<unsigned char> hash(std::vector<unsigned char> input);

}