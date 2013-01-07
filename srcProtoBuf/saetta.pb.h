// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: saetta.proto

#ifndef PROTOBUF_saetta_2eproto__INCLUDED
#define PROTOBUF_saetta_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2004000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2004001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace Saetta_Server {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_saetta_2eproto();
void protobuf_AssignDesc_saetta_2eproto();
void protobuf_ShutdownFile_saetta_2eproto();

class Server_Info;
class Server_Info_Client;
class Ping;
class Ping_TimeStamp;
class HeartBeat;

// ===================================================================

class Server_Info_Client : public ::google::protobuf::Message {
 public:
  Server_Info_Client();
  virtual ~Server_Info_Client();
  
  Server_Info_Client(const Server_Info_Client& from);
  
  inline Server_Info_Client& operator=(const Server_Info_Client& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Server_Info_Client& default_instance();
  
  void Swap(Server_Info_Client* other);
  
  // implements Message ----------------------------------------------
  
  Server_Info_Client* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Server_Info_Client& from);
  void MergeFrom(const Server_Info_Client& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required string name = 1;
  inline bool has_name() const;
  inline void clear_name();
  static const int kNameFieldNumber = 1;
  inline const ::std::string& name() const;
  inline void set_name(const ::std::string& value);
  inline void set_name(const char* value);
  inline void set_name(const char* value, size_t size);
  inline ::std::string* mutable_name();
  inline ::std::string* release_name();
  
  // required string address = 2;
  inline bool has_address() const;
  inline void clear_address();
  static const int kAddressFieldNumber = 2;
  inline const ::std::string& address() const;
  inline void set_address(const ::std::string& value);
  inline void set_address(const char* value);
  inline void set_address(const char* value, size_t size);
  inline ::std::string* mutable_address();
  inline ::std::string* release_address();
  
  // optional string status = 3;
  inline bool has_status() const;
  inline void clear_status();
  static const int kStatusFieldNumber = 3;
  inline const ::std::string& status() const;
  inline void set_status(const ::std::string& value);
  inline void set_status(const char* value);
  inline void set_status(const char* value, size_t size);
  inline ::std::string* mutable_status();
  inline ::std::string* release_status();
  
  // @@protoc_insertion_point(class_scope:Saetta_Server.Server_Info.Client)
 private:
  inline void set_has_name();
  inline void clear_has_name();
  inline void set_has_address();
  inline void clear_has_address();
  inline void set_has_status();
  inline void clear_has_status();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* name_;
  ::std::string* address_;
  ::std::string* status_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  friend void  protobuf_AddDesc_saetta_2eproto();
  friend void protobuf_AssignDesc_saetta_2eproto();
  friend void protobuf_ShutdownFile_saetta_2eproto();
  
  void InitAsDefaultInstance();
  static Server_Info_Client* default_instance_;
};
// -------------------------------------------------------------------

class Server_Info : public ::google::protobuf::Message {
 public:
  Server_Info();
  virtual ~Server_Info();
  
  Server_Info(const Server_Info& from);
  
  inline Server_Info& operator=(const Server_Info& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Server_Info& default_instance();
  
  void Swap(Server_Info* other);
  
  // implements Message ----------------------------------------------
  
  Server_Info* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Server_Info& from);
  void MergeFrom(const Server_Info& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  typedef Server_Info_Client Client;
  
  // accessors -------------------------------------------------------
  
  // required string time = 1;
  inline bool has_time() const;
  inline void clear_time();
  static const int kTimeFieldNumber = 1;
  inline const ::std::string& time() const;
  inline void set_time(const ::std::string& value);
  inline void set_time(const char* value);
  inline void set_time(const char* value, size_t size);
  inline ::std::string* mutable_time();
  inline ::std::string* release_time();
  
  // required string address = 2;
  inline bool has_address() const;
  inline void clear_address();
  static const int kAddressFieldNumber = 2;
  inline const ::std::string& address() const;
  inline void set_address(const ::std::string& value);
  inline void set_address(const char* value);
  inline void set_address(const char* value, size_t size);
  inline ::std::string* mutable_address();
  inline ::std::string* release_address();
  
  // repeated .Saetta_Server.Server_Info.Client known_clients = 3;
  inline int known_clients_size() const;
  inline void clear_known_clients();
  static const int kKnownClientsFieldNumber = 3;
  inline const ::Saetta_Server::Server_Info_Client& known_clients(int index) const;
  inline ::Saetta_Server::Server_Info_Client* mutable_known_clients(int index);
  inline ::Saetta_Server::Server_Info_Client* add_known_clients();
  inline const ::google::protobuf::RepeatedPtrField< ::Saetta_Server::Server_Info_Client >&
      known_clients() const;
  inline ::google::protobuf::RepeatedPtrField< ::Saetta_Server::Server_Info_Client >*
      mutable_known_clients();
  
  // @@protoc_insertion_point(class_scope:Saetta_Server.Server_Info)
 private:
  inline void set_has_time();
  inline void clear_has_time();
  inline void set_has_address();
  inline void clear_has_address();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* time_;
  ::std::string* address_;
  ::google::protobuf::RepeatedPtrField< ::Saetta_Server::Server_Info_Client > known_clients_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  friend void  protobuf_AddDesc_saetta_2eproto();
  friend void protobuf_AssignDesc_saetta_2eproto();
  friend void protobuf_ShutdownFile_saetta_2eproto();
  
  void InitAsDefaultInstance();
  static Server_Info* default_instance_;
};
// -------------------------------------------------------------------

class Ping_TimeStamp : public ::google::protobuf::Message {
 public:
  Ping_TimeStamp();
  virtual ~Ping_TimeStamp();
  
  Ping_TimeStamp(const Ping_TimeStamp& from);
  
  inline Ping_TimeStamp& operator=(const Ping_TimeStamp& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Ping_TimeStamp& default_instance();
  
  void Swap(Ping_TimeStamp* other);
  
  // implements Message ----------------------------------------------
  
  Ping_TimeStamp* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Ping_TimeStamp& from);
  void MergeFrom(const Ping_TimeStamp& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // optional string timestamp = 1;
  inline bool has_timestamp() const;
  inline void clear_timestamp();
  static const int kTimestampFieldNumber = 1;
  inline const ::std::string& timestamp() const;
  inline void set_timestamp(const ::std::string& value);
  inline void set_timestamp(const char* value);
  inline void set_timestamp(const char* value, size_t size);
  inline ::std::string* mutable_timestamp();
  inline ::std::string* release_timestamp();
  
  // optional uint64 itimestamp = 2;
  inline bool has_itimestamp() const;
  inline void clear_itimestamp();
  static const int kItimestampFieldNumber = 2;
  inline ::google::protobuf::uint64 itimestamp() const;
  inline void set_itimestamp(::google::protobuf::uint64 value);
  
  // required string station = 3;
  inline bool has_station() const;
  inline void clear_station();
  static const int kStationFieldNumber = 3;
  inline const ::std::string& station() const;
  inline void set_station(const ::std::string& value);
  inline void set_station(const char* value);
  inline void set_station(const char* value, size_t size);
  inline ::std::string* mutable_station();
  inline ::std::string* release_station();
  
  // @@protoc_insertion_point(class_scope:Saetta_Server.Ping.TimeStamp)
 private:
  inline void set_has_timestamp();
  inline void clear_has_timestamp();
  inline void set_has_itimestamp();
  inline void clear_has_itimestamp();
  inline void set_has_station();
  inline void clear_has_station();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* timestamp_;
  ::google::protobuf::uint64 itimestamp_;
  ::std::string* station_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];
  
  friend void  protobuf_AddDesc_saetta_2eproto();
  friend void protobuf_AssignDesc_saetta_2eproto();
  friend void protobuf_ShutdownFile_saetta_2eproto();
  
  void InitAsDefaultInstance();
  static Ping_TimeStamp* default_instance_;
};
// -------------------------------------------------------------------

class Ping : public ::google::protobuf::Message {
 public:
  Ping();
  virtual ~Ping();
  
  Ping(const Ping& from);
  
  inline Ping& operator=(const Ping& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const Ping& default_instance();
  
  void Swap(Ping* other);
  
  // implements Message ----------------------------------------------
  
  Ping* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Ping& from);
  void MergeFrom(const Ping& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  typedef Ping_TimeStamp TimeStamp;
  
  // accessors -------------------------------------------------------
  
  // required string origin = 1;
  inline bool has_origin() const;
  inline void clear_origin();
  static const int kOriginFieldNumber = 1;
  inline const ::std::string& origin() const;
  inline void set_origin(const ::std::string& value);
  inline void set_origin(const char* value);
  inline void set_origin(const char* value, size_t size);
  inline ::std::string* mutable_origin();
  inline ::std::string* release_origin();
  
  // repeated .Saetta_Server.Ping.TimeStamp timestamp = 2;
  inline int timestamp_size() const;
  inline void clear_timestamp();
  static const int kTimestampFieldNumber = 2;
  inline const ::Saetta_Server::Ping_TimeStamp& timestamp(int index) const;
  inline ::Saetta_Server::Ping_TimeStamp* mutable_timestamp(int index);
  inline ::Saetta_Server::Ping_TimeStamp* add_timestamp();
  inline const ::google::protobuf::RepeatedPtrField< ::Saetta_Server::Ping_TimeStamp >&
      timestamp() const;
  inline ::google::protobuf::RepeatedPtrField< ::Saetta_Server::Ping_TimeStamp >*
      mutable_timestamp();
  
  // @@protoc_insertion_point(class_scope:Saetta_Server.Ping)
 private:
  inline void set_has_origin();
  inline void clear_has_origin();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* origin_;
  ::google::protobuf::RepeatedPtrField< ::Saetta_Server::Ping_TimeStamp > timestamp_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  friend void  protobuf_AddDesc_saetta_2eproto();
  friend void protobuf_AssignDesc_saetta_2eproto();
  friend void protobuf_ShutdownFile_saetta_2eproto();
  
  void InitAsDefaultInstance();
  static Ping* default_instance_;
};
// -------------------------------------------------------------------

class HeartBeat : public ::google::protobuf::Message {
 public:
  HeartBeat();
  virtual ~HeartBeat();
  
  HeartBeat(const HeartBeat& from);
  
  inline HeartBeat& operator=(const HeartBeat& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const HeartBeat& default_instance();
  
  void Swap(HeartBeat* other);
  
  // implements Message ----------------------------------------------
  
  HeartBeat* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const HeartBeat& from);
  void MergeFrom(const HeartBeat& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required string origin = 1;
  inline bool has_origin() const;
  inline void clear_origin();
  static const int kOriginFieldNumber = 1;
  inline const ::std::string& origin() const;
  inline void set_origin(const ::std::string& value);
  inline void set_origin(const char* value);
  inline void set_origin(const char* value, size_t size);
  inline ::std::string* mutable_origin();
  inline ::std::string* release_origin();
  
  // required uint64 itimestamp = 2;
  inline bool has_itimestamp() const;
  inline void clear_itimestamp();
  static const int kItimestampFieldNumber = 2;
  inline ::google::protobuf::uint64 itimestamp() const;
  inline void set_itimestamp(::google::protobuf::uint64 value);
  
  // @@protoc_insertion_point(class_scope:Saetta_Server.HeartBeat)
 private:
  inline void set_has_origin();
  inline void clear_has_origin();
  inline void set_has_itimestamp();
  inline void clear_has_itimestamp();
  
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  
  ::std::string* origin_;
  ::google::protobuf::uint64 itimestamp_;
  
  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];
  
  friend void  protobuf_AddDesc_saetta_2eproto();
  friend void protobuf_AssignDesc_saetta_2eproto();
  friend void protobuf_ShutdownFile_saetta_2eproto();
  
  void InitAsDefaultInstance();
  static HeartBeat* default_instance_;
};
// ===================================================================


// ===================================================================

// Server_Info_Client

// required string name = 1;
inline bool Server_Info_Client::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Server_Info_Client::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Server_Info_Client::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Server_Info_Client::clear_name() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    name_->clear();
  }
  clear_has_name();
}
inline const ::std::string& Server_Info_Client::name() const {
  return *name_;
}
inline void Server_Info_Client::set_name(const ::std::string& value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Server_Info_Client::set_name(const char* value) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(value);
}
inline void Server_Info_Client::set_name(const char* value, size_t size) {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  name_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Server_Info_Client::mutable_name() {
  set_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    name_ = new ::std::string;
  }
  return name_;
}
inline ::std::string* Server_Info_Client::release_name() {
  clear_has_name();
  if (name_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = name_;
    name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required string address = 2;
inline bool Server_Info_Client::has_address() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Server_Info_Client::set_has_address() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Server_Info_Client::clear_has_address() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Server_Info_Client::clear_address() {
  if (address_ != &::google::protobuf::internal::kEmptyString) {
    address_->clear();
  }
  clear_has_address();
}
inline const ::std::string& Server_Info_Client::address() const {
  return *address_;
}
inline void Server_Info_Client::set_address(const ::std::string& value) {
  set_has_address();
  if (address_ == &::google::protobuf::internal::kEmptyString) {
    address_ = new ::std::string;
  }
  address_->assign(value);
}
inline void Server_Info_Client::set_address(const char* value) {
  set_has_address();
  if (address_ == &::google::protobuf::internal::kEmptyString) {
    address_ = new ::std::string;
  }
  address_->assign(value);
}
inline void Server_Info_Client::set_address(const char* value, size_t size) {
  set_has_address();
  if (address_ == &::google::protobuf::internal::kEmptyString) {
    address_ = new ::std::string;
  }
  address_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Server_Info_Client::mutable_address() {
  set_has_address();
  if (address_ == &::google::protobuf::internal::kEmptyString) {
    address_ = new ::std::string;
  }
  return address_;
}
inline ::std::string* Server_Info_Client::release_address() {
  clear_has_address();
  if (address_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = address_;
    address_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional string status = 3;
inline bool Server_Info_Client::has_status() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Server_Info_Client::set_has_status() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Server_Info_Client::clear_has_status() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Server_Info_Client::clear_status() {
  if (status_ != &::google::protobuf::internal::kEmptyString) {
    status_->clear();
  }
  clear_has_status();
}
inline const ::std::string& Server_Info_Client::status() const {
  return *status_;
}
inline void Server_Info_Client::set_status(const ::std::string& value) {
  set_has_status();
  if (status_ == &::google::protobuf::internal::kEmptyString) {
    status_ = new ::std::string;
  }
  status_->assign(value);
}
inline void Server_Info_Client::set_status(const char* value) {
  set_has_status();
  if (status_ == &::google::protobuf::internal::kEmptyString) {
    status_ = new ::std::string;
  }
  status_->assign(value);
}
inline void Server_Info_Client::set_status(const char* value, size_t size) {
  set_has_status();
  if (status_ == &::google::protobuf::internal::kEmptyString) {
    status_ = new ::std::string;
  }
  status_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Server_Info_Client::mutable_status() {
  set_has_status();
  if (status_ == &::google::protobuf::internal::kEmptyString) {
    status_ = new ::std::string;
  }
  return status_;
}
inline ::std::string* Server_Info_Client::release_status() {
  clear_has_status();
  if (status_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = status_;
    status_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// -------------------------------------------------------------------

// Server_Info

// required string time = 1;
inline bool Server_Info::has_time() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Server_Info::set_has_time() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Server_Info::clear_has_time() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Server_Info::clear_time() {
  if (time_ != &::google::protobuf::internal::kEmptyString) {
    time_->clear();
  }
  clear_has_time();
}
inline const ::std::string& Server_Info::time() const {
  return *time_;
}
inline void Server_Info::set_time(const ::std::string& value) {
  set_has_time();
  if (time_ == &::google::protobuf::internal::kEmptyString) {
    time_ = new ::std::string;
  }
  time_->assign(value);
}
inline void Server_Info::set_time(const char* value) {
  set_has_time();
  if (time_ == &::google::protobuf::internal::kEmptyString) {
    time_ = new ::std::string;
  }
  time_->assign(value);
}
inline void Server_Info::set_time(const char* value, size_t size) {
  set_has_time();
  if (time_ == &::google::protobuf::internal::kEmptyString) {
    time_ = new ::std::string;
  }
  time_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Server_Info::mutable_time() {
  set_has_time();
  if (time_ == &::google::protobuf::internal::kEmptyString) {
    time_ = new ::std::string;
  }
  return time_;
}
inline ::std::string* Server_Info::release_time() {
  clear_has_time();
  if (time_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = time_;
    time_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required string address = 2;
inline bool Server_Info::has_address() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Server_Info::set_has_address() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Server_Info::clear_has_address() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Server_Info::clear_address() {
  if (address_ != &::google::protobuf::internal::kEmptyString) {
    address_->clear();
  }
  clear_has_address();
}
inline const ::std::string& Server_Info::address() const {
  return *address_;
}
inline void Server_Info::set_address(const ::std::string& value) {
  set_has_address();
  if (address_ == &::google::protobuf::internal::kEmptyString) {
    address_ = new ::std::string;
  }
  address_->assign(value);
}
inline void Server_Info::set_address(const char* value) {
  set_has_address();
  if (address_ == &::google::protobuf::internal::kEmptyString) {
    address_ = new ::std::string;
  }
  address_->assign(value);
}
inline void Server_Info::set_address(const char* value, size_t size) {
  set_has_address();
  if (address_ == &::google::protobuf::internal::kEmptyString) {
    address_ = new ::std::string;
  }
  address_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Server_Info::mutable_address() {
  set_has_address();
  if (address_ == &::google::protobuf::internal::kEmptyString) {
    address_ = new ::std::string;
  }
  return address_;
}
inline ::std::string* Server_Info::release_address() {
  clear_has_address();
  if (address_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = address_;
    address_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// repeated .Saetta_Server.Server_Info.Client known_clients = 3;
inline int Server_Info::known_clients_size() const {
  return known_clients_.size();
}
inline void Server_Info::clear_known_clients() {
  known_clients_.Clear();
}
inline const ::Saetta_Server::Server_Info_Client& Server_Info::known_clients(int index) const {
  return known_clients_.Get(index);
}
inline ::Saetta_Server::Server_Info_Client* Server_Info::mutable_known_clients(int index) {
  return known_clients_.Mutable(index);
}
inline ::Saetta_Server::Server_Info_Client* Server_Info::add_known_clients() {
  return known_clients_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Saetta_Server::Server_Info_Client >&
Server_Info::known_clients() const {
  return known_clients_;
}
inline ::google::protobuf::RepeatedPtrField< ::Saetta_Server::Server_Info_Client >*
Server_Info::mutable_known_clients() {
  return &known_clients_;
}

// -------------------------------------------------------------------

// Ping_TimeStamp

// optional string timestamp = 1;
inline bool Ping_TimeStamp::has_timestamp() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Ping_TimeStamp::set_has_timestamp() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Ping_TimeStamp::clear_has_timestamp() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Ping_TimeStamp::clear_timestamp() {
  if (timestamp_ != &::google::protobuf::internal::kEmptyString) {
    timestamp_->clear();
  }
  clear_has_timestamp();
}
inline const ::std::string& Ping_TimeStamp::timestamp() const {
  return *timestamp_;
}
inline void Ping_TimeStamp::set_timestamp(const ::std::string& value) {
  set_has_timestamp();
  if (timestamp_ == &::google::protobuf::internal::kEmptyString) {
    timestamp_ = new ::std::string;
  }
  timestamp_->assign(value);
}
inline void Ping_TimeStamp::set_timestamp(const char* value) {
  set_has_timestamp();
  if (timestamp_ == &::google::protobuf::internal::kEmptyString) {
    timestamp_ = new ::std::string;
  }
  timestamp_->assign(value);
}
inline void Ping_TimeStamp::set_timestamp(const char* value, size_t size) {
  set_has_timestamp();
  if (timestamp_ == &::google::protobuf::internal::kEmptyString) {
    timestamp_ = new ::std::string;
  }
  timestamp_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Ping_TimeStamp::mutable_timestamp() {
  set_has_timestamp();
  if (timestamp_ == &::google::protobuf::internal::kEmptyString) {
    timestamp_ = new ::std::string;
  }
  return timestamp_;
}
inline ::std::string* Ping_TimeStamp::release_timestamp() {
  clear_has_timestamp();
  if (timestamp_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = timestamp_;
    timestamp_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// optional uint64 itimestamp = 2;
inline bool Ping_TimeStamp::has_itimestamp() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Ping_TimeStamp::set_has_itimestamp() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Ping_TimeStamp::clear_has_itimestamp() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Ping_TimeStamp::clear_itimestamp() {
  itimestamp_ = GOOGLE_ULONGLONG(0);
  clear_has_itimestamp();
}
inline ::google::protobuf::uint64 Ping_TimeStamp::itimestamp() const {
  return itimestamp_;
}
inline void Ping_TimeStamp::set_itimestamp(::google::protobuf::uint64 value) {
  set_has_itimestamp();
  itimestamp_ = value;
}

// required string station = 3;
inline bool Ping_TimeStamp::has_station() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Ping_TimeStamp::set_has_station() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Ping_TimeStamp::clear_has_station() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Ping_TimeStamp::clear_station() {
  if (station_ != &::google::protobuf::internal::kEmptyString) {
    station_->clear();
  }
  clear_has_station();
}
inline const ::std::string& Ping_TimeStamp::station() const {
  return *station_;
}
inline void Ping_TimeStamp::set_station(const ::std::string& value) {
  set_has_station();
  if (station_ == &::google::protobuf::internal::kEmptyString) {
    station_ = new ::std::string;
  }
  station_->assign(value);
}
inline void Ping_TimeStamp::set_station(const char* value) {
  set_has_station();
  if (station_ == &::google::protobuf::internal::kEmptyString) {
    station_ = new ::std::string;
  }
  station_->assign(value);
}
inline void Ping_TimeStamp::set_station(const char* value, size_t size) {
  set_has_station();
  if (station_ == &::google::protobuf::internal::kEmptyString) {
    station_ = new ::std::string;
  }
  station_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Ping_TimeStamp::mutable_station() {
  set_has_station();
  if (station_ == &::google::protobuf::internal::kEmptyString) {
    station_ = new ::std::string;
  }
  return station_;
}
inline ::std::string* Ping_TimeStamp::release_station() {
  clear_has_station();
  if (station_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = station_;
    station_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// -------------------------------------------------------------------

// Ping

// required string origin = 1;
inline bool Ping::has_origin() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Ping::set_has_origin() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Ping::clear_has_origin() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Ping::clear_origin() {
  if (origin_ != &::google::protobuf::internal::kEmptyString) {
    origin_->clear();
  }
  clear_has_origin();
}
inline const ::std::string& Ping::origin() const {
  return *origin_;
}
inline void Ping::set_origin(const ::std::string& value) {
  set_has_origin();
  if (origin_ == &::google::protobuf::internal::kEmptyString) {
    origin_ = new ::std::string;
  }
  origin_->assign(value);
}
inline void Ping::set_origin(const char* value) {
  set_has_origin();
  if (origin_ == &::google::protobuf::internal::kEmptyString) {
    origin_ = new ::std::string;
  }
  origin_->assign(value);
}
inline void Ping::set_origin(const char* value, size_t size) {
  set_has_origin();
  if (origin_ == &::google::protobuf::internal::kEmptyString) {
    origin_ = new ::std::string;
  }
  origin_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* Ping::mutable_origin() {
  set_has_origin();
  if (origin_ == &::google::protobuf::internal::kEmptyString) {
    origin_ = new ::std::string;
  }
  return origin_;
}
inline ::std::string* Ping::release_origin() {
  clear_has_origin();
  if (origin_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = origin_;
    origin_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// repeated .Saetta_Server.Ping.TimeStamp timestamp = 2;
inline int Ping::timestamp_size() const {
  return timestamp_.size();
}
inline void Ping::clear_timestamp() {
  timestamp_.Clear();
}
inline const ::Saetta_Server::Ping_TimeStamp& Ping::timestamp(int index) const {
  return timestamp_.Get(index);
}
inline ::Saetta_Server::Ping_TimeStamp* Ping::mutable_timestamp(int index) {
  return timestamp_.Mutable(index);
}
inline ::Saetta_Server::Ping_TimeStamp* Ping::add_timestamp() {
  return timestamp_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Saetta_Server::Ping_TimeStamp >&
Ping::timestamp() const {
  return timestamp_;
}
inline ::google::protobuf::RepeatedPtrField< ::Saetta_Server::Ping_TimeStamp >*
Ping::mutable_timestamp() {
  return &timestamp_;
}

// -------------------------------------------------------------------

// HeartBeat

// required string origin = 1;
inline bool HeartBeat::has_origin() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void HeartBeat::set_has_origin() {
  _has_bits_[0] |= 0x00000001u;
}
inline void HeartBeat::clear_has_origin() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void HeartBeat::clear_origin() {
  if (origin_ != &::google::protobuf::internal::kEmptyString) {
    origin_->clear();
  }
  clear_has_origin();
}
inline const ::std::string& HeartBeat::origin() const {
  return *origin_;
}
inline void HeartBeat::set_origin(const ::std::string& value) {
  set_has_origin();
  if (origin_ == &::google::protobuf::internal::kEmptyString) {
    origin_ = new ::std::string;
  }
  origin_->assign(value);
}
inline void HeartBeat::set_origin(const char* value) {
  set_has_origin();
  if (origin_ == &::google::protobuf::internal::kEmptyString) {
    origin_ = new ::std::string;
  }
  origin_->assign(value);
}
inline void HeartBeat::set_origin(const char* value, size_t size) {
  set_has_origin();
  if (origin_ == &::google::protobuf::internal::kEmptyString) {
    origin_ = new ::std::string;
  }
  origin_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* HeartBeat::mutable_origin() {
  set_has_origin();
  if (origin_ == &::google::protobuf::internal::kEmptyString) {
    origin_ = new ::std::string;
  }
  return origin_;
}
inline ::std::string* HeartBeat::release_origin() {
  clear_has_origin();
  if (origin_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = origin_;
    origin_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}

// required uint64 itimestamp = 2;
inline bool HeartBeat::has_itimestamp() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void HeartBeat::set_has_itimestamp() {
  _has_bits_[0] |= 0x00000002u;
}
inline void HeartBeat::clear_has_itimestamp() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void HeartBeat::clear_itimestamp() {
  itimestamp_ = GOOGLE_ULONGLONG(0);
  clear_has_itimestamp();
}
inline ::google::protobuf::uint64 HeartBeat::itimestamp() const {
  return itimestamp_;
}
inline void HeartBeat::set_itimestamp(::google::protobuf::uint64 value) {
  set_has_itimestamp();
  itimestamp_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Saetta_Server

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_saetta_2eproto__INCLUDED
