
pub trait BitManipulation {
    fn extract(&self, offset: usize, length: usize) -> Self; 
    fn deposit(&mut self, value: Self, offset: usize, length: usize);
}

impl BitManipulation for u32 {
    fn extract(&self, offset: usize, length: usize) -> Self {
        assert!(offset < 32 && offset + length <= 32);
        *self >> offset & (!0u32 >> (32 - length))
    }

    fn deposit(&mut self, value: Self, offset: usize, length: usize) {
        assert!(offset < 32 && offset + length <= 32);
        let mask = (!0u32 >> (32 - length)) << offset;
        *self = (*self & !mask) | ((value << offset) & mask);
    }
}


#[cfg(test)]
mod tests {
    use super::BitManipulation;

    #[test]
    fn test_extract() {
        let num = 0xFAFAu32;
        assert_eq!(num.extract(8, 8), 0xFAu32);
        assert_eq!(num.extract(24, 4), 0u32);
    }
    
    #[test]
    fn test_deposit() {
        let mut num = 0x12345678u32;
        num.deposit(0xF, 4, 4);
        num.deposit(0xF, 12, 4);
        num.deposit(0xF, 20, 4);
        num.deposit(0xF, 28, 4);
        assert_eq!(num, 0xF2F4F6F8u32)
    }

    #[test]
    #[should_panic]
    fn test_extract_panic() {
        let num = 0x12345678u32;
        num.extract(33, 4);
        num.extract(12, 24);
    }
}