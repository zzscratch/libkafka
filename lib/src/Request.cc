//////////////////////////////////////////////////////////////////
//                                                              //
// libkafka - C/C++ client for Apache Kafka v0.8+               //
//                                                              //
// David Tompkins -- 8/8/2013                                   //
// http://dt.org/                                               //
//                                                              //
// Copyright (c) 2013 by David Tompkins.                        //
//                                                              //
//////////////////////////////////////////////////////////////////
//                                                              //
// This program is free software; you can redistribute it       //
// and/or modify it under the terms of the GNU General Public   //
// License as published by the Free Software Foundation.        //
//                                                              //
// This program is distributed in the hope that it will be      //
// useful, but WITHOUT ANY WARRANTY; without even the implied   //
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR      //
// PURPOSE. See the GNU General Public License for more details //
//                                                              //
// You should have received a copy of the GNU General Public    //
// License along with this program; if not, write to the Free   //
// Software Foundation, Inc., 59 Temple Place, Suite 330,       //
// Boston, MA 02111-1307 USA                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include <iostream>

#include <Request.h>

using namespace std;

Request::Request(unsigned char *buffer) : RequestOrResponse(buffer)
{
  D(cout << "--------------Request()\n";)
  // Kafka Protocol: short int apiKey
  this->apiKey = read_int16();

  // Kafka Protocol: short int apiVersion
  this->apiVersion = read_int16();
 
  // Kafka Protocol: int correlationId
  this->correlationId = read_int32();

  // Kafka Protocol: kafka string clientId
  this->clientId = read_string();
}
