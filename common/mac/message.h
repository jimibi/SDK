/*
 * message - The message layer public common code
 *
 * Copyright (c) 2018, Archos S.A.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * * Neither the name of Archos nor the names of its contributors may be
 *   used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS'' AND
 * AND EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ARCHOS S.A. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include "message_common.h"

enum ack_request {
	WITHOUT_ACK,
	WITH_ACK
};

typedef enum {
	MSG_STATUS_FORMAT_ERROR = -4,
	MSG_STATUS_MIC_ERROR = -3,
	MSG_STATUS_LENGTH_ERROR = -2,
	MSG_STATUS_HEADER_ERROR = -1,
	MSG_STATUS_NO_ERROR = 0,
} message_status_t;

/**
 * @brief  Initializes the frame's type.
 * @param  frame_format: type of the MAC
 */
void message_init_format(message_format_t frame_format);

/**
 * @brief  Initializes the session keys. Network session AES128 key and application session AES128 key.
 * @param  nwkskey: Pointer to the network session AES128 key array ( 16 bytes )
 * @param  appskey: Pointer to the application session AES128 key array ( 16 bytes )
 */
void message_init_session_keys(uint8_t *nwkskey, uint8_t *appskey);

/**
  * @brief  Initializes the network IDs. Device address, network session AES128 key and application session AES128 key.
  * @param  netid: 24 bits network identifier ( provided by network operator )
  * @param  devaddr: 32 bits device address on the network (must be unique to the network)
  * @param  nwkskey: Pointer to the network session AES128 key array ( 16 bytes )
  * @param  appskey: Pointer to the application session AES128 key array ( 16 bytes )
  */
void message_init_ids(uint32_t netid, uint32_t devaddr, uint8_t *nwkskey, uint8_t *appskey);


/**
  * @brief  compose a message according to some inputs
  * @param  type: message type
  * @param  port: payload port (0 for mac specific message else must be > 0 for application data)
  * @param  payload: A pointer to the data to send
  * @param  payload_len: The length of the data to send
  * @param  seqno: frame counter
  * @param  msg:  A pointer to composed message
  * @return message_status
  */
message_status_t message_compose(uint8_t type, uint8_t port, const uint8_t *payload, uint8_t payload_len, uint8_t *fopts, uint8_t fopts_len,
				 uint16_t seqno, message_t *msg);


/**
 * @brief  compose a special message for OTA
 * @param  type: message type
 * @param  dev_eui: pointer to the device EUI array (8 bytes)
 * @param  app_eui: pointer to the application EUI array (8 bytes)
 * @param  app_key: pointer to the application AES128 key array (16 bytes)
 * @return message_status
 */
message_status_t message_compose_join_OTA(uint8_t type, uint8_t *dev_eui, uint8_t *app_eui, uint16_t *dev_nonce, uint8_t *app_key, message_t *msg);


/**
  * @brief  decode a message according to format choosen
  * @param  buf: A pointer to the data to decode
  * @param  buf_len: The length of the data to decode
  * @param  msg:  A pointer to decoded message
  * @return message_status
  */
message_status_t message_decode(uint8_t *buf, uint8_t buf_len, message_t *msg);

/**
 * @brief  decode a message from OTA
 * @param  buf: A pointer to the data to decode
 * @param  buf_len: The length of the data to decode
 * @param  app_key: pointer to the application AES128 key array (16 bytes)
 * @param  appskey: Pointer to the application session AES128 key array ( 16 bytes )
 * @param  nwkskey: Pointer to the network session AES128 key array ( 16 bytes )
 * @param  dev_nonce: ramdom nonce to create session keys
 * @param  netid: 24 bits network identifier ( provided by network operator )
 * @param  devaddr: 32 bits device address on the network (must be unique to the network)
 * @param  rx1_dr_offset: datarate offset between uplink and downlink on first window
 * @param  rx2_dr: datarate on the second window
 * @param  rx_delay: delay to wait before starting the first windows
 * @param  cf_list: channels available
 * @return message_status
 */
message_status_t message_decode_join_OTA(uint8_t *buf, uint8_t buf_len, uint8_t *app_key, uint8_t *appskey, uint8_t *nwkskey, uint16_t *dev_nonce,
					 uint32_t *netid, uint32_t *devaddr, uint8_t *rx1_dr_offset, uint8_t *rx2_dr, uint8_t *rx_delay,
					 uint8_t *cf_list);

/**
  * @brief  compute message integrity check
  * @param  msg:  A pointer to encoded message
  * @return message_status
  */
message_status_t message_authentication(message_t *msg);

/**
  * @brief  check if message type needs an acknowledgement
  * @param  msg:  A pointer to a given message
  * @return 0 ack_request enum, NO_ACK in case of error
  */
enum ack_request message_ack_request(message_t *msg);

/**
  * @brief  return message direction
  * @param  type:  message type
  * @return 1 if downlink, 0 if uplink or error
  */
uint8_t message_get_direction(uint8_t type);

/**
  * @brief  Return maximun allowed bytes for user payload
  * @return max payload length or 0
  */
uint16_t message_max_payload_length();

/**
 * @brief  Get the address of the frame
 * @param  buf: A pointer to the data to decode
 * @param  buf_len: The length of the data to decode
 * @param  msg:  A pointer to save address message
 * @return message_status
 */
message_status_t message_get_address(uint8_t *buf, uint8_t buf_len, message_t *msg);

/**
 * @brief  Get frame header
 * @param  buf: A pointer to the data to decode
 * @param  buf_len: The length of the data to decode
 * @param  msg:  A pointer to save header message
 * @return message_status
 */
message_status_t message_get_header(uint8_t *buf, uint8_t buf_len, message_t *msg);

#endif /* _MESSAGE_H_ */
