#include "excelaccessorerror.h"

ExcelAccessorError::ExcelAccessorError(QObject *parent)
    : ExcelAccessor{parent}
{

}


void ExcelAccessorError::readCells()
{
    emit readError("Error Test");
}
