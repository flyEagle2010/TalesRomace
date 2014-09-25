// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: hero.proto

#ifndef PROTOBUF_hero_2eproto__INCLUDED
#define PROTOBUF_hero_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_hero_2eproto();
void protobuf_AssignDesc_hero_2eproto();
void protobuf_ShutdownFile_hero_2eproto();

class PAscend;
class PEvolve;
class PMutation;
class PCallHero;
class PGoldQualityUpgrade;

// ===================================================================

class PAscend : public ::google::protobuf::Message {
 public:
  PAscend();
  virtual ~PAscend();

  PAscend(const PAscend& from);

  inline PAscend& operator=(const PAscend& from) {
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
  static const PAscend& default_instance();

  void Swap(PAscend* other);

  // implements Message ----------------------------------------------

  PAscend* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PAscend& from);
  void MergeFrom(const PAscend& from);
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

  // required int64 heroId = 1;
  inline bool has_heroid() const;
  inline void clear_heroid();
  static const int kHeroIdFieldNumber = 1;
  inline ::google::protobuf::int64 heroid() const;
  inline void set_heroid(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:PAscend)
 private:
  inline void set_has_heroid();
  inline void clear_has_heroid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 heroid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_hero_2eproto();
  friend void protobuf_AssignDesc_hero_2eproto();
  friend void protobuf_ShutdownFile_hero_2eproto();

  void InitAsDefaultInstance();
  static PAscend* default_instance_;
};
// -------------------------------------------------------------------

class PEvolve : public ::google::protobuf::Message {
 public:
  PEvolve();
  virtual ~PEvolve();

  PEvolve(const PEvolve& from);

  inline PEvolve& operator=(const PEvolve& from) {
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
  static const PEvolve& default_instance();

  void Swap(PEvolve* other);

  // implements Message ----------------------------------------------

  PEvolve* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PEvolve& from);
  void MergeFrom(const PEvolve& from);
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

  // required int64 heroId = 1;
  inline bool has_heroid() const;
  inline void clear_heroid();
  static const int kHeroIdFieldNumber = 1;
  inline ::google::protobuf::int64 heroid() const;
  inline void set_heroid(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:PEvolve)
 private:
  inline void set_has_heroid();
  inline void clear_has_heroid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 heroid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_hero_2eproto();
  friend void protobuf_AssignDesc_hero_2eproto();
  friend void protobuf_ShutdownFile_hero_2eproto();

  void InitAsDefaultInstance();
  static PEvolve* default_instance_;
};
// -------------------------------------------------------------------

class PMutation : public ::google::protobuf::Message {
 public:
  PMutation();
  virtual ~PMutation();

  PMutation(const PMutation& from);

  inline PMutation& operator=(const PMutation& from) {
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
  static const PMutation& default_instance();

  void Swap(PMutation* other);

  // implements Message ----------------------------------------------

  PMutation* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PMutation& from);
  void MergeFrom(const PMutation& from);
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

  // required int64 heroId = 1;
  inline bool has_heroid() const;
  inline void clear_heroid();
  static const int kHeroIdFieldNumber = 1;
  inline ::google::protobuf::int64 heroid() const;
  inline void set_heroid(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:PMutation)
 private:
  inline void set_has_heroid();
  inline void clear_has_heroid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 heroid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_hero_2eproto();
  friend void protobuf_AssignDesc_hero_2eproto();
  friend void protobuf_ShutdownFile_hero_2eproto();

  void InitAsDefaultInstance();
  static PMutation* default_instance_;
};
// -------------------------------------------------------------------

class PCallHero : public ::google::protobuf::Message {
 public:
  PCallHero();
  virtual ~PCallHero();

  PCallHero(const PCallHero& from);

  inline PCallHero& operator=(const PCallHero& from) {
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
  static const PCallHero& default_instance();

  void Swap(PCallHero* other);

  // implements Message ----------------------------------------------

  PCallHero* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PCallHero& from);
  void MergeFrom(const PCallHero& from);
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

  // required int32 heroId = 1;
  inline bool has_heroid() const;
  inline void clear_heroid();
  static const int kHeroIdFieldNumber = 1;
  inline ::google::protobuf::int32 heroid() const;
  inline void set_heroid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:PCallHero)
 private:
  inline void set_has_heroid();
  inline void clear_has_heroid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 heroid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_hero_2eproto();
  friend void protobuf_AssignDesc_hero_2eproto();
  friend void protobuf_ShutdownFile_hero_2eproto();

  void InitAsDefaultInstance();
  static PCallHero* default_instance_;
};
// -------------------------------------------------------------------

class PGoldQualityUpgrade : public ::google::protobuf::Message {
 public:
  PGoldQualityUpgrade();
  virtual ~PGoldQualityUpgrade();

  PGoldQualityUpgrade(const PGoldQualityUpgrade& from);

  inline PGoldQualityUpgrade& operator=(const PGoldQualityUpgrade& from) {
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
  static const PGoldQualityUpgrade& default_instance();

  void Swap(PGoldQualityUpgrade* other);

  // implements Message ----------------------------------------------

  PGoldQualityUpgrade* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PGoldQualityUpgrade& from);
  void MergeFrom(const PGoldQualityUpgrade& from);
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

  // required int32 result = 1;
  inline bool has_result() const;
  inline void clear_result();
  static const int kResultFieldNumber = 1;
  inline ::google::protobuf::int32 result() const;
  inline void set_result(::google::protobuf::int32 value);

  // optional int32 changeFlag = 2;
  inline bool has_changeflag() const;
  inline void clear_changeflag();
  static const int kChangeFlagFieldNumber = 2;
  inline ::google::protobuf::int32 changeflag() const;
  inline void set_changeflag(::google::protobuf::int32 value);

  // optional int32 skillId = 3;
  inline bool has_skillid() const;
  inline void clear_skillid();
  static const int kSkillIdFieldNumber = 3;
  inline ::google::protobuf::int32 skillid() const;
  inline void set_skillid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:PGoldQualityUpgrade)
 private:
  inline void set_has_result();
  inline void clear_has_result();
  inline void set_has_changeflag();
  inline void clear_has_changeflag();
  inline void set_has_skillid();
  inline void clear_has_skillid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 result_;
  ::google::protobuf::int32 changeflag_;
  ::google::protobuf::int32 skillid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_hero_2eproto();
  friend void protobuf_AssignDesc_hero_2eproto();
  friend void protobuf_ShutdownFile_hero_2eproto();

  void InitAsDefaultInstance();
  static PGoldQualityUpgrade* default_instance_;
};
// ===================================================================


// ===================================================================

// PAscend

// required int64 heroId = 1;
inline bool PAscend::has_heroid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PAscend::set_has_heroid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PAscend::clear_has_heroid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PAscend::clear_heroid() {
  heroid_ = GOOGLE_LONGLONG(0);
  clear_has_heroid();
}
inline ::google::protobuf::int64 PAscend::heroid() const {
  return heroid_;
}
inline void PAscend::set_heroid(::google::protobuf::int64 value) {
  set_has_heroid();
  heroid_ = value;
}

// -------------------------------------------------------------------

// PEvolve

// required int64 heroId = 1;
inline bool PEvolve::has_heroid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PEvolve::set_has_heroid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PEvolve::clear_has_heroid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PEvolve::clear_heroid() {
  heroid_ = GOOGLE_LONGLONG(0);
  clear_has_heroid();
}
inline ::google::protobuf::int64 PEvolve::heroid() const {
  return heroid_;
}
inline void PEvolve::set_heroid(::google::protobuf::int64 value) {
  set_has_heroid();
  heroid_ = value;
}

// -------------------------------------------------------------------

// PMutation

// required int64 heroId = 1;
inline bool PMutation::has_heroid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PMutation::set_has_heroid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PMutation::clear_has_heroid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PMutation::clear_heroid() {
  heroid_ = GOOGLE_LONGLONG(0);
  clear_has_heroid();
}
inline ::google::protobuf::int64 PMutation::heroid() const {
  return heroid_;
}
inline void PMutation::set_heroid(::google::protobuf::int64 value) {
  set_has_heroid();
  heroid_ = value;
}

// -------------------------------------------------------------------

// PCallHero

// required int32 heroId = 1;
inline bool PCallHero::has_heroid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PCallHero::set_has_heroid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PCallHero::clear_has_heroid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PCallHero::clear_heroid() {
  heroid_ = 0;
  clear_has_heroid();
}
inline ::google::protobuf::int32 PCallHero::heroid() const {
  return heroid_;
}
inline void PCallHero::set_heroid(::google::protobuf::int32 value) {
  set_has_heroid();
  heroid_ = value;
}

// -------------------------------------------------------------------

// PGoldQualityUpgrade

// required int32 result = 1;
inline bool PGoldQualityUpgrade::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PGoldQualityUpgrade::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PGoldQualityUpgrade::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PGoldQualityUpgrade::clear_result() {
  result_ = 0;
  clear_has_result();
}
inline ::google::protobuf::int32 PGoldQualityUpgrade::result() const {
  return result_;
}
inline void PGoldQualityUpgrade::set_result(::google::protobuf::int32 value) {
  set_has_result();
  result_ = value;
}

// optional int32 changeFlag = 2;
inline bool PGoldQualityUpgrade::has_changeflag() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PGoldQualityUpgrade::set_has_changeflag() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PGoldQualityUpgrade::clear_has_changeflag() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PGoldQualityUpgrade::clear_changeflag() {
  changeflag_ = 0;
  clear_has_changeflag();
}
inline ::google::protobuf::int32 PGoldQualityUpgrade::changeflag() const {
  return changeflag_;
}
inline void PGoldQualityUpgrade::set_changeflag(::google::protobuf::int32 value) {
  set_has_changeflag();
  changeflag_ = value;
}

// optional int32 skillId = 3;
inline bool PGoldQualityUpgrade::has_skillid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void PGoldQualityUpgrade::set_has_skillid() {
  _has_bits_[0] |= 0x00000004u;
}
inline void PGoldQualityUpgrade::clear_has_skillid() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void PGoldQualityUpgrade::clear_skillid() {
  skillid_ = 0;
  clear_has_skillid();
}
inline ::google::protobuf::int32 PGoldQualityUpgrade::skillid() const {
  return skillid_;
}
inline void PGoldQualityUpgrade::set_skillid(::google::protobuf::int32 value) {
  set_has_skillid();
  skillid_ = value;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_hero_2eproto__INCLUDED