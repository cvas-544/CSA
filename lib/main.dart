import 'package:flutter/material.dart';
import 'package:permission_handler/permission_handler.dart';
import 'package:scandit_flutter_datacapture_barcode/scandit_flutter_datacapture_barcode.dart';
import 'package:scandit_flutter_datacapture_barcode/scandit_flutter_datacapture_barcode_capture.dart';
import 'package:scandit_flutter_datacapture_core/scandit_flutter_datacapture_core.dart';

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await ScanditFlutterDataCaptureBarcode.initialize();
  runApp(MyApp());
}

// Enter your Scandit License key here.
const String licenseKey = 'AiSVbSnnDNToP6i7HNgfMIozinACOSIg6R6JddMIozl8TnrB4l8ibIthLcQJZ1ajn3Du/F5uBxAwVEG0yGHhRBBKD5Ckbfd0XXIhsSUuK/mZBn0e2HYNEwFQBHU/OcydOyAbCVcCflSwauE9vC9lShI1071ELPPJ9Vuq0OF6QfmaF1zbaACgVBMTNcD/K15CMXQngns0bxBxGxd2wjmaLzY8cEghNvDSeS/Pi41tWd8MHwsNyWc6z90k9d7iGFQZbngtSMNT6vZnR5WATwWf+fMYdEl7AFvbYX0GT1EZyENsQX7QVydXYewV60zkKpQDFgoiWeoiT36aILMD1xjHMgQBNknzfmBRWFX6ywdT31AxahNEfEfL4H9uho6gcOdMqiTKhMd08si4d/f0vmfsQoVgE/bOWbyU/1NaZBFoGzNqSnkm9UjbLhdnfTS3Tf70HE29ae1yToxLSoLcsmtQT8J9GD7MXVUeX1XVAk53FYajXBEtfBQUv+NQOHdvbRhElGkr+QdzzzqKYQDS+0OF+cJJwbKVdlwrZ3K8jPRHy88dVjw8GHvuXm9veMgeS/P+ZRGOINkaGHnbUNN7FEfDa79Cc5L/ZXBi03VgkARcarvCDqABlUtCaK1phGT4YEGaHGmstr8AT1HsStLUA1vUdF9ihuKvM65iG2oeixJP4Z0wTl88yhM1LR5hSSSKZFYvOltHlexd9tvbR93+ezjqQxUVBd5ybIho22lUn2heda77dbupRmzKn6hppL/eGJHBFDoKsZdBomK7Oa8JT1GbwHRCkb5iFo3bQnHkZ0Nn+tZvTdqpYAFo82EGgrp1QFe7/SjyTzxzGKU0IcinIWoLvHJDzIreLMrG71iff6EUruJaJA4vNUK2xXlBpAy7SEr3ASfAaSYZXnNAN5jm4WKtfB9tnwVvY2Pvc0uIhZREvV+mcgVGfGgaE+hVxeoudVGvAEokkU4o2hA1HEW5qXtWWTgJy2+3VhGnUFF7745pHjadVTMPrn0qBYNYOxtuRRey+EB/jfV+eCjPXkvQ1HL+iZFS/NvpDoAdBgfZJnxwnyWCctrXTnnLTxIVyxzNT4y4fnledo4OFynPcLlPmyRLcyJHIGLVdJ3EQ2BGJG5I8MMhSM6YTGUvgp1WL4kNDqAEBlNnfCxuVgXAULR4N0efrapugHycd2bNxGF7DNBrMc8jRrjwJVnWoBxca0s0NdRxZIJ2noA1O6XvHYOC87H2J6FtA7nTuVunVAR7p7McLz3P2BaFtcbDJhfgScZ0K+dJIjkc5wGZJTqHibqXgsP7Md2yhAFunk5Tvmrw9ezvA8U97tpPies6pbOwOgx+UMyptsPJApv7ybl5Q21ULXIzJLV1yLIlqUncI6WMaEzTrtscMIBYzSmunmZDHclWb2c0RSnT9fYxD7vPGiBbIEPJ5hz15TBvBfAd7+jlNBfr1OuMASn/KKKx6ljZ7AWYLqJkHKnOQ0l8sicqBBBenmI8try3YrtOJwCBEU7h+m2/79B2Tenxlld5KVyoaIcTNz691o8hP9RumVdTn1CiHIs0QlL4v+BaCxPUH0JeP/XFZf25XulfaFIGUx9VHlj+v6yYqrXpjbBkUFU/xh+Czrzqm4bsi7lrkN+Zd/vLcE/z6QHbneW6SrOSnW1BMY1YyFm2Em3QQZ49NiuOMd7gT6ZCxwAz+b7+PuruQzy/Ubkqi+exxEQtYfYlx0TyvCLu2W8kiw1xg0yg8iw0gAFQZ9D6ecxI+Auhbt09dcyIrlBENo5V3kWeniWepbK/hmg9wCzDIhKjhIVoEsWmEoEMzdXjLu8z/eOlDHnQ1XN8VuH1y1iL66RBFS1vzvHSNWxUjZuV0VxdkMgCYQTfFouMB2tKfzVvHcXov8yj0GDYx0+A7nA=';

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      theme: ThemeData(
        useMaterial3: true,
      ),
      home: MainAppScreen(),
    );
  }
}

class MainAppScreen extends StatefulWidget {
  @override
  _MainAppScreenState createState() => _MainAppScreenState();
}

class _MainAppScreenState extends State<MainAppScreen> {
  int _currentIndex = 0;

  final List<Widget> _pages = [
    HomeScreen(),
    BarcodeScannerScreen(),
    AccountScreen(),
  ];

  void _onTabTapped(int index) {
    setState(() {
      _currentIndex = index;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: _pages[_currentIndex],
      bottomNavigationBar: BottomNavigationBar(
        currentIndex: _currentIndex,
        onTap: _onTabTapped,
        selectedItemColor: Colors.greenAccent,
        unselectedItemColor: Colors.black,
        items: const [
          BottomNavigationBarItem(
            icon: Icon(Icons.home),
            label: 'Home',
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.qr_code_scanner),
            label: 'Scan',
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.person),
            label: 'Account',
          ),
        ],
      ),
    );
  }
}

class HomeScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: Text(
          "Welcome to Home Screen",
          style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
        ),
      ),
    );
  }
}

class AccountScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: Center(
        child: Text(
          "Welcome to Account Screen",
          style: TextStyle(fontSize: 24, fontWeight: FontWeight.bold),
        ),
      ),
    );
  }
}

class BarcodeScannerScreen extends StatefulWidget {
  @override
  State<StatefulWidget> createState() =>
      _BarcodeScannerScreenState(DataCaptureContext.forLicenseKey(licenseKey));
}

class _BarcodeScannerScreenState extends State<BarcodeScannerScreen>
    with WidgetsBindingObserver
    implements BarcodeCaptureListener {
  final DataCaptureContext _context;

  Camera? _camera = Camera.defaultCamera;
  late BarcodeCapture _barcodeCapture;
  late DataCaptureView _captureView;

  bool _isPermissionMessageVisible = false;

  _BarcodeScannerScreenState(this._context);

  void _checkPermission() {
    Permission.camera.request().isGranted.then((value) => setState(() {
      _isPermissionMessageVisible = !value;
      if (value) {
        _camera?.switchToDesiredState(FrameSourceState.on);
      }
    }));
  }

  @override
  void initState() {
    super.initState();
    _ambiguate(WidgetsBinding.instance)?.addObserver(this);

    _camera?.applySettings(BarcodeCapture.recommendedCameraSettings);

    _checkPermission();

    var captureSettings = BarcodeCaptureSettings();
    captureSettings.enableSymbologies({
      Symbology.ean8,
      Symbology.ean13Upca,
      Symbology.upce,
      Symbology.qr,
      Symbology.dataMatrix,
      Symbology.code39,
      Symbology.code128,
      Symbology.interleavedTwoOfFive,
    });

    captureSettings.settingsForSymbology(Symbology.code39).activeSymbolCounts =
        [for (var i = 7; i <= 20; i++) i].toSet();

    _barcodeCapture = BarcodeCapture.forContext(_context, captureSettings)
      ..addListener(this);

    _captureView = DataCaptureView.forContext(_context);

    var overlay = BarcodeCaptureOverlay.withBarcodeCaptureForViewWithStyle(
        _barcodeCapture, _captureView, BarcodeCaptureOverlayStyle.frame)
      ..viewfinder = RectangularViewfinder.withStyleAndLineStyle(
          RectangularViewfinderStyle.square, RectangularViewfinderLineStyle.light);

    overlay.brush = Brush(Color.fromARGB(0, 0, 0, 0), Color.fromARGB(255, 255, 255, 255), 3);

    _captureView.addOverlay(overlay);

    if (_camera != null) {
      _context.setFrameSource(_camera!);
    }
    _camera?.switchToDesiredState(FrameSourceState.on);
    _barcodeCapture.isEnabled = true;
  }

  @override
  Widget build(BuildContext context) {
    Widget child;
    if (_isPermissionMessageVisible) {
      child = Text(
        'No permission to access the camera!',
        style: TextStyle(fontSize: 14, fontWeight: FontWeight.bold, color: Colors.black),
      );
    } else {
      child = _captureView;
    }
    return Scaffold(
      body: Center(child: child),
    );
  }

  @override
  void didChangeAppLifecycleState(AppLifecycleState state) {
    if (state == AppLifecycleState.resumed) {
      _checkPermission();
    } else if (state == AppLifecycleState.paused) {
      _camera?.switchToDesiredState(FrameSourceState.off);
    }
  }

  @override
  Future<void> didScan(
      BarcodeCapture barcodeCapture, BarcodeCaptureSession session, Future<FrameData> getFrameData()) async {
    _barcodeCapture.isEnabled = false;
    var code = session.newlyRecognizedBarcode;
    if (code == null) return;

    var data = (code.data == null || code.data?.isEmpty == true) ? code.rawData : code.data;
    var humanReadableSymbology = SymbologyDescription.forSymbology(code.symbology);
    showDialog(
        context: context,
        builder: (_) => AlertDialog(
          content: Text(
            'Scanned: $data\n (${humanReadableSymbology.readableName})',
            style: TextStyle(fontWeight: FontWeight.bold, fontSize: 16),
          ),
          actions: [
            TextButton(
                child: Text("OK"),
                onPressed: () {
                  Navigator.of(context, rootNavigator: true).pop();
                })
          ],
        )).then((result) => _barcodeCapture.isEnabled = true);
  }

  @override
  Future<void> didUpdateSession(
      BarcodeCapture barcodeCapture, BarcodeCaptureSession session, Future<FrameData> getFrameData()) async {
    // Handle session updates if needed
  }

  @override
  void dispose() {
    _ambiguate(WidgetsBinding.instance)?.removeObserver(this);
    _barcodeCapture.removeListener(this);
    _barcodeCapture.isEnabled = false;
    _camera?.switchToDesiredState(FrameSourceState.off);
    _context.removeAllModes();
    super.dispose();
  }

  T? _ambiguate<T>(T? value) => value;
}
