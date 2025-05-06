# Stack in C with Unit Tests

這是一個使用 C 語言實作的 堆疊（Stack）資料結構，採用 linked list和 array 作為內部儲存方式，並以 CUnit 撰寫基本單元測試。

## 專案結構

```bash
.
└── ./Linked_list_implement
│   ├── include/                 # 標頭檔
│   │   └── Stack_linkedlist.h
│   ├── src/                    # 程式實作
│   │   └── Stack_linkedlist.c
│   ├── test/                   # 測試檔案
│   │   └── test.c
│   ├── Makefile                
│   └── README.md
│
└── ./Array implement
    ├── include/                 # 標頭檔
    │   └── Stack_array.h
    ├── src/                    # 程式實作
    │   └── Stack_array.c
    ├── test/                   # 測試檔案
    │   └── test.c
    ├── Makefile                
    └── README.md   
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