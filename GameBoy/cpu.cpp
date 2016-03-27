#include "cpu.h"

Cpu::Cpu(std::string filename) : cart_(filename){
    //ctor
}

Cpu::Cpu(Cartridge &cart) : cart_(cart){

}

void Cpu::ExecuteInstruction(char instruction){
	//char instruction = instruction >> 24;
  auto& r = registers_;

	switch (instruction){
  case 0x00: break;//NOP
  case 0x01: //LD BC, nn
    r.C = m_.read_byte(PC_); 
    r.B = m_.read_byte(PC_ + 1); 
    PC_ += 2; 
    break;
  case 0x02: //LD (BC), A
    m_.write_byte(r.size_16.BC, r.A); 
    break; 
  case 0x03: //INC BC
    r.size_16.BC += 1; 
    break;
  case 0x04: //INC B
    ++r.B; 
    flags_.zero       = r.B == 0; 
    flags_.half_carry = (r.B & 0xF) == 0; 
    flags_.subtract   = false;
    break;
  case 0x05: //DEC B
    --r.B;
    flags_.zero       = r.B == 0;
    flags_.half_carry = (r.B & 0xF) == 0;
    flags_.subtract = true;
    break;
  case 0x06: //LD B, n
    r.B = m_.read_byte(PC_);
    ++PC_;
    break;
  case 0x07: //RLCA
    flags_.carry = r.A > 0x7F;
    r.A = (r.A << 1) | (r.A >> 7);//rotate byte
    flags_.zero       = false;
    flags_.subtract   = false;
    flags_.half_carry = false;
    break;
  case 0x08: //LD (nn), SP
    SP_ = m_.read_word_16(PC_);
    PC_ += 2;
    break;
  case 0x09: { //ADD HL, BC
    //needs to be bigger than 16 bits to check for overflow
    //this approach avoids branching
    uint32_t sum = r.size_16.HL + r.size_16.BC;
    flags_.half_carry = ((r.size_16.HL & 0xFFF) > (sum & 0xFFF));
    flags_.carry      = sum > 0xFFFF;
    r.size_16.HL      = sum;
    flags_.subtract   = false;
  }
    break;
  case 0x0A: //LD A, (BC)
    r.A = m_.read_byte(r.size_16.BC);
    break;
  case 0x0B: //DEC BC 
    --r.size_16.BC;
    break;
  case 0x0C: //INC C
    ++r.C;
    flags_.zero       = r.C == 0;
    flags_.half_carry = (r.C & 0xF) == 0;
    flags_.subtract   = false;
    break;
  case 0x0D: break;
  case 0x0E: break;
  case 0x0F: break;
  case 0x10: break;
  case 0x11: break;
  case 0x12: break;
  case 0x13: break;
  case 0x14: break;
  case 0x15: break;
  case 0x16: break;
  case 0x17: break;
  case 0x18: break;
  case 0x19: break;
  case 0x1A: break;
  case 0x1B: break;
  case 0x1C: break;
  case 0x1D: break;
  case 0x1E: break;
  case 0x1F: break;
  case 0x20: break;
  case 0x21: break;
  case 0x22: break;
  case 0x23: break;
  case 0x24: break;
  case 0x25: break;
  case 0x26: break;
  case 0x27: break;
  case 0x28: break;
  case 0x29: break;
  case 0x2A: break;
  case 0x2B: break;
  case 0x2C: break;
  case 0x2D: break;
  case 0x2E: break;
  case 0x2F: break;
  case 0x30: break;
  case 0x31: break;
  case 0x32: break;
  case 0x33: break;
  case 0x34: break;
  case 0x35: break;
  case 0x36: break;
  case 0x37: break;
  case 0x38: break;
  case 0x39: break;
  case 0x3A: break;
  case 0x3B: break;
  case 0x3C: break;
  case 0x3D: break;
  case 0x3E: break;
  case 0x3F: break;
	case 0x40: break;
  case 0x41: break;
  case 0x42: break;
  case 0x43: break;
  case 0x44: break;
  case 0x45: break;
  case 0x46: break;
  case 0x47: break;
  case 0x48: break;
  case 0x49: break;
  case 0x4A: break;
  case 0x4B: break;
  case 0x4C: break;
  case 0x4D: break;
  case 0x4E: break;
  case 0x4F: break;
	//row 5
	case 0x50: break;
  case 0x51: break;
  case 0x52: break;
  case 0x53: break;
  case 0x54: break;
  case 0x55: break;
  case 0x56: break;
  case 0x57: break;
  case 0x58: break;
  case 0x59: break;
  case 0x5A: break;
  case 0x5B: break;
  case 0x5C: break;
  case 0x5D: break;
  case 0x5E: break;
  case 0x5F: break;
	case 0x60: break;
  case 0x61: break;
  case 0x62: break;
  case 0x63: break;
  case 0x64: break;
  case 0x65: break;
  case 0x66: break;
  case 0x67: break;
  case 0x68: break;
  case 0x69: break;
  case 0x6A: break;
  case 0x6B: break;
  case 0x6C: break;
  case 0x6D: break;
  case 0x6E: break;
  case 0x6F: break;
	case 0x70: break;
  case 0x71: break;
  case 0x72: break;
  case 0x73: break;
  case 0x74: break;
  case 0x75: break;
  case 0x76: break;
  case 0x77: break;
  case 0x78: break;
  case 0x79: break;
  case 0x7A: break;
  case 0x7B: break;
  case 0x7C: break;
  case 0x7D: break;
  case 0x7E: break;
  case 0x7F: break;
  case 0x80: break;
  case 0x81: break;
  case 0x82: break;
  case 0x83: break;
  case 0x84: break;
  case 0x85: break;
  case 0x86: break;
  case 0x87: break;
  case 0x88: break;
  case 0x89: break;
  case 0x8A: break;
  case 0x8B: break;
  case 0x8C: break;
  case 0x8D: break;
  case 0x8E: break;
  case 0x8F: break;
  case 0x90: break;
  case 0x91: break;
  case 0x92: break;
  case 0x93: break;
  case 0x94: break;
  case 0x95: break;
  case 0x96: break;
  case 0x97: break;
  case 0x98: break;
  case 0x99: break;
  case 0x9A: break;
  case 0x9B: break;
  case 0x9C: break;
  case 0x9D: break;
  case 0x9E: break;
  case 0x9F: break;
  case 0xA0: break;
  case 0xA1: break;
  case 0xA2: break;
  case 0xA3: break;
  case 0xA4: break;
  case 0xA5: break;
  case 0xA6: break;
  case 0xA7: break;
  case 0xA8: break;
  case 0xA9: break;
  case 0xAA: break;
  case 0xAB: break;
  case 0xAC: break;
  case 0xAD: break;
  case 0xAE: break;
  case 0xAF: break;
  case 0xB0: break;
  case 0xB1: break;
  case 0xB2: break;
  case 0xB3: break;
  case 0xB4: break;
  case 0xB5: break;
  case 0xB6: break;
  case 0xB7: break;
  case 0xB8: break;
  case 0xB9: break;
  case 0xBA: break;
  case 0xBB: break;
  case 0xBC: break;
  case 0xBD: break;
  case 0xBE: break;
  case 0xBF: break;
  case 0xC0: break;
  case 0xC1: break;
  case 0xC2: break;
  case 0xC3: break;
  case 0xC4: break;
  case 0xC5: break;
  case 0xC6: break;
  case 0xC7: break;
  case 0xC8: break;
  case 0xC9: break;
  case 0xCA: break;
  case 0xCB: break;
  case 0xCC: break;
  case 0xCD: break;
  case 0xCE: break;
  case 0xCF: break;
  case 0xD0: break;
  case 0xD1: break;
  case 0xD2: break;
  case 0xD4: break;
  case 0xD5: break;
  case 0xD6: break;
  case 0xD7: break;
  case 0xD8: break;
  case 0xD9: break;
  case 0xDA: break;
  case 0xDC: break;
  case 0xDE: break;
  case 0xDF: break;
  case 0xE0: break;
  case 0xE1: break;
  case 0xE2: break;
  case 0xE5: break;
  case 0xE6: break;
  case 0xE7: break;
  case 0xE8: break;
  case 0xE9: break;
  case 0xEA: break;
  case 0xEE: break;
  case 0xEF: break;
  case 0xF0: break;
  case 0xF1: break;
  case 0xF2: break;
  case 0xF3: break;
  case 0xF5: break;
  case 0xF6: break;
  case 0xF7: break;
  case 0xF8: break;
  case 0xF9: break;
  case 0xFA: break;
  case 0xFB: break;
  case 0xFE: break;
  case 0xFF: break;
  default:		throw std::invalid_argument("instruction not implemented: " + (int)instruction); break;
	}
}