#ifndef __KITE_REG_FILE_H__
#define __KITE_REG_FILE_H__

#include <stdint.h>
#include "inst.h"

// Register file
class reg_file_t {
public:
    reg_file_t();
    ~reg_file_t();

    int64_t read(unsigned m_index) const;           // Read register file.
    void write(inst_t *m_inst, unsigned m_index, int64_t m_value);  // Write register file.
    bool dep_check(inst_t *m_inst);                 // Data dependency check
    void flush();                                   // Clear dependency check state.
    void load_reg_state();                          // Load initial register file state.

private:
    int64_t regs[num_kite_regs];                    // Array of 64-bit registers
    inst_t *dep[num_kite_regs];                     // Dependency check table
};

#endif

