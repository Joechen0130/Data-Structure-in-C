# Queue in C with Unit Tests

這是一個使用 C 語言實作的 Queue 資料結構，採用 linked list和 array 作為內部儲存方式，並以 CUnit 撰寫基本單元測試。

## 專案結構

```bash
.
└── ./LinkedList_Implement
│   ├── include/                
│   │   └── Queue_linkedlist.h
│   ├── src/                   
│   │   └── Queue_linkedlist.c
│   ├── test/                   
│   │   └── test.c
│   ├── Makefile
│
└── ./Array Implement
│   ├── include/                 
│   │   └── Queue_array.h
│   ├── src/                    
│   │   └── Queue_array.c
│   ├── test/                   
│   │   └── test.c
│   ├── Makefile
│
└── ./Circular_Array Implement
    ├── include/                 
    │   └── Queue_circular_array.h
    ├── src/                   
    │   └── Queue_circular_array.c
    ├── test/                   
    │   └── test.c
    ├── Makefile   
```

## 安裝 CUnit
```bash
sudo apt update
sudo apt install libcunit1-dev
```

## 建置專案
```bash
make
```

## 執行test case
```bash
./testexe
```

## GitHub Actions CI 支援
已配置 .github/workflows/ci.yml，當你推送程式到 GitHub 時，會自動進行建置與測試。