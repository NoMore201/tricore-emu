#ifndef TRICORE_EMU_CPU_HPP
#define TRICORE_EMU_CPU_HPP

#include "Bus.hpp"
#include "Elf.hpp"
#include "Types.hpp"

#include <fmt/format.h>
#include <gsl/pointers>

#include <stdexcept>
#include <string>

namespace Tricore {

struct InvalidRegisterOffset : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class Cpu {

public:
    explicit Cpu(Bus& bus);

    void initialize_program(Elf& elf_file);

    void set_program_counter(u32 address) noexcept
    {
        m_core_registers.pc = address;
    }

    void start();

private:
    static constexpr usize register_count = 16;

    // Instruction handlers
    void insn_movha();
    void insn_mov_rlc();
    void insn_lea_bol();
    void insn_ji_sr();
    void insn_mtcr();
    void insn_isync();
    void insn_dsync();
    void insn_ldw_slr();
    void insn_ldw_bol();
    void insn_add_c2();
    void insn_movh();
    void insn_and_srr();
    void insn_jne_brc();
    void insn_suba_rr();
    void insn_movd_srr();
    void insn_stw_bol();
    void insn_jli();
    void insn_jnzt_brn();
    void insn_ldbu_bol();
    void insn_or_rc();
    void insn_stb_bol();
    void insn_jne_brr();
    void insn_jltu_brc();
    void insn_nop();
    void insn_j_b();
    void insn_jgeu_brc();
    void insn_extru_rrpw();
    void insn_sh_src();
    void insn_xor_rc();
    void insn_insert_rcpw();
    void insn_or_srr();
    void insn_stw_ssr();
    void insn_lha_abs();
    void insn_ne_rc();
    void insn_ne_rr();
    void insn_andne_rr();
    void insn_andne_rc();
    void insn_addi_rlc();
    void insn_mov_src();
    void insn_sh_rc();
    void insn_mova_src();
    void insn_call_32();
    void insn_jeq_brc();
    void insn_mova_srr();
    void insn_addsca_rr();
    void insn_jeq_brr();
    void insn_mov_srr();
    void insn_movaa_srr();
    void insn_suba_sc();
    void insn_sth_bol();
    void insn_sta_bol();
    void insn_ldhu_bol();
    void insn_lda_bol();
    void insn_and_rc();
    void insn_mfcr();
    void insn_minu_rr();
    void insn_ldh_bol();
    void insn_ret_sr();
    void insn_movu_rlc();
    void insn_not_sr();
    void insn_andn_rc();
    void insn_divu_rr();
    void insn_sub_rr();
    void insn_utof_rr();

    // Helpers

    [[noreturn]] void fail(std::string message);
    void print_cpu_status();

    // CPU registers
    struct DataRegisters {
        u32 d0 {};
        u32 d1 {};
        u32 d2 {};
        u32 d3 {};
        u32 d4 {};
        u32 d5 {};
        u32 d6 {};
        u32 d7 {};
        u32 d8 {};
        u32 d9 {};
        u32 d10 {};
        u32 d11 {};
        u32 d12 {};
        u32 d13 {};
        u32 d14 {};
        u32 d15 {};

        u32& operator[](usize offset);
    } m_data_reg;

    struct AddressRegisters {
        u32 a0 {};
        u32 a1 {};
        u32 a2 {};
        u32 a3 {};
        u32 a4 {};
        u32 a5 {};
        u32 a6 {};
        u32 a7 {};
        u32 a8 {};
        u32 a9 {};
        u32 a10 {};
        u32 a11 {};
        u32 a12 {};
        u32 a13 {};
        u32 a14 {};
        u32 a15 {};

        u32& operator[](usize offset);
    } m_addr_reg;

    struct CoreRegisters {
        u32 pcxi { 0 };
        u32 psw { 0xB80U };
        u32 pc { 0 };
        u32 syscon { 0 };
        u32 cpu_id { 0 };
        u32 core_id { 0 };
        u32 biv { 0 };
        u32 btv { 0 };
        u32 isp { 0 };
        u32 icr { 0 };
        u32 fcx { 0 };
        u32 lcx { 0 };

        u32& operator[](usize offset);

    } m_core_registers;

    Bus::RequestHandler m_bus;
};

} // namespace Tricore

#endif // ifndef TRICORE_EMU_CPU_HPP
