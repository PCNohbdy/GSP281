#ifndef TABLES_H
#define TABLES_H

class Tables
{
public:
	enum TABLETYPE{BOOTH,STOOL,TABLE};
	enum TABLESTATE{CLEAN,DIRTY,OCCUPIED};
	inline int GetSize()const{return M_Size;};
	inline TABLESTATE GetTableState()const{return M_TableState;}
	inline TABLETYPE GetTableType()const{return M_TableType;}
	Tables(TABLETYPE);
	~Tables();
private:
	int M_Size;
	TABLETYPE  M_TableType;
	TABLESTATE M_TableState;
};



#endif