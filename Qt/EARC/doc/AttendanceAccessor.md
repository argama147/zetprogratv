第１段階：ExcelAccessor構成
```mermaid
classDiagram
    class ExcelAccessor {
        void readCells()
    }
    <<interface>> ExcelAccessor
    class ExcelAccessorActiveQt {
    }
    class ExcelAccessorOdbc {
    }
    ExcelAccessor <|-- ExcelAccessorActiveQt
    ExcelAccessor <|-- ExcelAccessorOdbc
```

第２段階：AttendanceAccessor周り
```mermaid
classDiagram
    class MainWindow {
    }
    class AttendanceAccessor {
    }
    class ExcelAccessor {
        void readCells()
    }
    <<interface>> ExcelAccessor
    class ExcelAccessorActiveQt {
        void readCells()
    }
    class ExcelAccessorOdbc {
        void readCells()
    }
    ExcelAccessor <|-- ExcelAccessorActiveQt
    ExcelAccessor <|-- ExcelAccessorOdbc
    MainWindow ..|> AttendanceAccessor : use
    AttendanceAccessor ..|> ExcelAccessorActiveQt : create
    AttendanceAccessor ..|> ExcelAccessor : use
    AttendanceAccessor ..|> ExcelAccessorOdbc : create
```

第３段階：BuilderパターンでAttendanceAccessorを生成
```mermaid
classDiagram
    class MainWindow {
    }
    class Builder {
        setBuilderType()
        setFilePath()
        setSheetName()
        setSheetNo()
        setRowStartNo()
        setRowNum()
        setColumnStartNo()
        setColumnNum()
    }
    class AttendanceAccessor {
    }
    class ExcelAccessor {
        void readCells()
    }
    <<interface>> ExcelAccessor
    class ExcelAccessorActiveQt {
        void readCells()
    }
    class ExcelAccessorOdbc {
        void readCells()
    }
    ExcelAccessor <|-- ExcelAccessorActiveQt
    ExcelAccessor <|-- ExcelAccessorOdbc
    MainWindow ..|> Builder : use
    MainWindow ..|> AttendanceAccessor : use
    AttendanceAccessor ..|> ExcelAccessorActiveQt : create
    AttendanceAccessor ..|> ExcelAccessor : use
    AttendanceAccessor ..|> ExcelAccessorOdbc : create
    Builder ..|> AttendanceAccessor : create
```
