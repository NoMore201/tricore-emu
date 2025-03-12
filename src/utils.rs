pub trait BitManipulation {
    fn extract(&self, offset: usize, length: usize) -> Self;
    fn deposit(&self, value: Self, offset: usize, length: usize) -> Self;
    fn sign_extend(&self, original_bits: u32) -> Self;
}

impl BitManipulation for u32 {
    fn extract(&self, offset: usize, length: usize) -> Self {
        assert!(offset < 32 && offset + length <= 32);
        *self >> offset & (!0u32 >> (32 - length))
    }

    fn deposit(&self, value: Self, offset: usize, length: usize) -> Self {
        assert!(offset < 32 && offset + length <= 32);
        let mask = (!0u32 >> (32 - length)) << offset;
        (*self & !mask) | ((value << offset) & mask)
    }

    fn sign_extend(&self, from_bit: u32) -> Self {
        assert!(from_bit != 0 && from_bit < Self::BITS);
        let mut cleared_input = *self & ((1u32 << from_bit) - 1u32);
        let sign_bit_mask = 1u32 << (from_bit - 1u32);
        cleared_input ^= sign_bit_mask;
        cleared_input.wrapping_sub(sign_bit_mask)
    }
}

#[cfg(test)]
mod tests {
    use super::BitManipulation;

    #[test]
    fn test_extract() {
        let num = 0xFAFAu32;
        assert_eq!(num.extract(8, 8), 0xFAu32);
        assert_eq!(num.extract(18, 14), 0u32);
        assert_eq!(num.extract(24, 4), 0u32);

        let num2 = 0x80000000u32;
        assert_eq!(num2.extract(31, 1), 1u32);
    }

    #[test]
    fn test_deposit() {
        let mut num = 0x12345678u32;
        num = num.deposit(0xF, 4, 4);
        num = num.deposit(0xF, 12, 4);
        num = num.deposit(0xF, 20, 4);
        num = num.deposit(0xF, 28, 4);
        assert_eq!(num, 0xF2F4F6F8u32)
    }

    #[test]
    fn test_sign_extend() {
        assert_eq!(1u32.sign_extend(31), 1u32);
        assert_eq!(0xFFu32.sign_extend(8), 0xFFFFFFFFu32);
        assert_eq!(0x18u32.sign_extend(5), 0xFFFFFFF8u32);
    }

    #[test]
    #[should_panic(expected = "assertion failed")]
    fn test_extract_invalid_offset_panic() {
        let num = 0x12345678u32;
        num.extract(33, 4);
        num.extract(12, 24);
    }

    #[test]
    #[should_panic(expected = "assertion failed")]
    fn test_extract_invalid_length_panic() {
        let num = 0x12345678u32;
        num.extract(12, 44);
    }

    #[test]
    #[should_panic(expected = "assertion failed")]
    fn test_extract_invalid_offset_length_panic() {
        let num = 0x12345678u32;
        num.extract(12, 24);
    }

    #[test]
    #[should_panic(expected = "assertion failed")]
    fn test_deposit_invalid_offset_panic() {
        let mut num = 0x12345678u32;
        num.deposit(12, 123, 1);
    }

    #[test]
    #[should_panic(expected = "assertion failed")]
    fn test_deposit_invalid_length_panic() {
        let mut num = 0x12345678u32;
        num.deposit(12, 1, 40);
    }

    #[test]
    #[should_panic(expected = "assertion failed")]
    fn test_deposit_invalid_offset_length_panic() {
        let mut num = 0x12345678u32;
        num.deposit(12, 24, 11);
    }
}
