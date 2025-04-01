
pub const KiB: usize = 1024;
pub const MiB: usize = KiB * KiB;

pub trait BitManipulation {
    fn extract(&self, offset: usize, length: usize) -> Self;
    fn deposit(&self, value: Self, offset: usize, length: usize) -> Self;
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
}

impl BitManipulation for u16 {
    fn extract(&self, offset: usize, length: usize) -> Self {
        assert!(offset < 16 && offset + length <= 16);
        *self >> offset & (!0u16 >> (16 - length))
    }

    fn deposit(&self, value: Self, offset: usize, length: usize) -> Self {
        assert!(offset < 16 && offset + length <= 16);
        let mask = (!0u16 >> (16 - length)) << offset;
        (*self & !mask) | ((value << offset) & mask)
    }
}

pub fn sign_extend(value: i32, from_bit: u32) -> i32 {
    let notherbits = std::mem::size_of_val(&value) as u32 * 8 - from_bit;
    value.wrapping_shl(notherbits).wrapping_shr(notherbits)
}

#[cfg(test)]
mod tests {
    use super::{sign_extend, BitManipulation};

    #[test]
    fn test_extract() {
        let num = 0xFAFAu32;
        assert_eq!(num.extract(8, 8), 0xFAu32);
        assert_eq!(num.extract(18, 14), 0u32);
        assert_eq!(num.extract(24, 4), 0u32);

        let num2 = 0x80000000u32;
        assert_eq!(num2.extract(31, 1), 1u32);

        let num16 = 0x5D5Du16;
        assert_eq!(num16.extract(8, 4), 0xDu16);
        assert_eq!(num16.extract(4, 12), 0x5D5u16);
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
        assert_eq!(sign_extend(1, 31), 1);
        assert_eq!(sign_extend(0xFF, 8), -1);
        assert_eq!(sign_extend(0x18, 5), -8);
    }

    #[test]
    #[should_panic(expected = "assertion failed")]
    fn test_extract32_invalid_offset_panic() {
        let num = 0x12345678u32;
        num.extract(33, 4);
    }

    #[test]
    #[should_panic(expected = "assertion failed")]
    fn test_extract32_invalid_length_panic() {
        let num = 0x12345678u32;
        num.extract(12, 44);
    }

    #[test]
    #[should_panic(expected = "assertion failed")]
    fn test_extract32_invalid_offset_length_panic() {
        let num = 0x12345678u32;
        num.extract(12, 24);
    }

    #[test]
    #[should_panic(expected = "assertion failed")]
    fn test_extract16_invalid_offset_panic() {
        let num = 0x5678u16;
        num.extract(20, 4);
    }

    #[test]
    #[should_panic(expected = "assertion failed")]
    fn test_extract16_invalid_length_panic() {
        let num = 0x5678u16;
        num.extract(12, 17);
    }

    #[test]
    #[should_panic(expected = "assertion failed")]
    fn test_extract16_invalid_offset_length_panic() {
        let num = 0x5678u16;
        num.extract(4, 13);
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
