#ifndef _tracer_hpp_INCLUDED
#define _tracer_hpp_INCLUDED

namespace CaDiCaL {

// Proof tracer class to observer all possible proof events,
// such as added or deleted clauses.
// An implementation can decide on which events to act.

class Tracer {

public:
  Tracer () {}
  virtual ~Tracer () {}
  
  // Notify the tracer that a original clause has been added.
  // Includes ID and wether the clause is redundant or irredundant
  //
  virtual void add_original_clause (uint64_t, bool, const vector<int> &) {}

  // Notify the observer that a new clause has been derived.
  // Includes ID and wether the clause is redundant or irredundant
  // If antecedents are derived they will be included here.
  //
  virtual void add_derived_clause (uint64_t, bool, const vector<int> &, const vector<uint64_t> &) {}

  // Notify the observer that a clause is deleted.
  // Includes ID and redundant/irredundant
  //
  virtual void delete_clause (uint64_t, bool, const vector<int> &) {}

  // Notify the observer that a clause is finalized.
  // Includes ID
  //
  virtual void finalize_clause (uint64_t, const vector<int> &) {}

  // Notify the observer that the proof ends with global empty clause
  // Includes ID
  // Note that the empty clause is already added through add_derived_clause
  // and finalized with finalize_clause
  //
  virtual void finalize_proof (uint64_t) {}

  // Notify the observer that the proof begins with a set of reserved ids for
  // original clauses.
  // Given ID is the first derived clause ID.
  //
  virtual void begin_proof (uint64_t) {}

};

class StatTracer : public Tracer {

public:
  StatTracer () {}
  virtual ~StatTracer () {}
  
  virtual void print_stats () {}

};

class FileTracer : public Tracer {

public:
  FileTracer () {}
  virtual ~FileTracer () {}
  
  virtual bool closed () { return true; }
  virtual void close () {}
  virtual void flush () {}

};


} // namespace CaDiCaL

#endif
