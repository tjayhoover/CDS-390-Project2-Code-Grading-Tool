#include "student_report_view.hpp"

#include <iostream>

void StudentReportView::display(ViewModel data) {
    std::cout << data.output << std::endl;
}