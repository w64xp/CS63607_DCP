import sys
import serial
from PyQt6.QtWidgets import (
    QApplication, QWidget, QPushButton, QVBoxLayout,
    QLabel, QComboBox, QMessageBox, QHBoxLayout
)
from PyQt6.QtCore import Qt
import serial.tools.list_ports


class LEDControlApp(QWidget):
    def __init__(self):
        super().__init__()

        self.serial_port = None

        self.setWindowTitle("Arduino RGB LED Control")
        self.setGeometry(300, 200, 350, 300)

        self.title = QLabel("ควบคุมไฟ Red Green Blue")
        self.title.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.combo_port = QComboBox()
        self.load_ports()

        self.btn_connect = QPushButton("Connect")
        self.btn_connect.clicked.connect(self.connect_serial)

        self.btn_red = QPushButton("RED")
        self.btn_green = QPushButton("GREEN")
        self.btn_blue = QPushButton("BLUE")
        self.btn_off = QPushButton("OFF")

        self.btn_red.clicked.connect(lambda: self.send_command("RED"))
        self.btn_green.clicked.connect(lambda: self.send_command("GREEN"))
        self.btn_blue.clicked.connect(lambda: self.send_command("BLUE"))
        self.btn_off.clicked.connect(lambda: self.send_command("OFF"))

        port_layout = QHBoxLayout()
        port_layout.addWidget(self.combo_port)
        port_layout.addWidget(self.btn_connect)

        layout = QVBoxLayout()
        layout.addWidget(self.title)
        layout.addLayout(port_layout)
        layout.addWidget(self.btn_red)
        layout.addWidget(self.btn_green)
        layout.addWidget(self.btn_blue)
        layout.addWidget(self.btn_off)

        self.setLayout(layout)

    def load_ports(self):
        ports = serial.tools.list_ports.comports()
        for port in ports:
            self.combo_port.addItem(port.device)

    def connect_serial(self):
        port_name = self.combo_port.currentText()

        if port_name == "":
            QMessageBox.warning(self, "Warning", "ไม่พบ COM Port")
            return

        try:
            self.serial_port = serial.Serial(port_name, 9600, timeout=1)
            QMessageBox.information(self, "Success", f"Connected to {port_name}")
        except Exception as e:
            QMessageBox.critical(self, "Error", str(e))

    def send_command(self, command):
        if self.serial_port and self.serial_port.is_open:
            self.serial_port.write((command + "\n").encode())
        else:
            QMessageBox.warning(self, "Warning", "กรุณา Connect COM Port ก่อน")


if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = LEDControlApp()
    window.show()
    sys.exit(app.exec())