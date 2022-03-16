#pragma once

enum Mode {
  Info,
  Success,
  Warning,
  Error,
  Critical,
};

enum StatusCode {
  CreatedFiles,
  NoFile,
  PathNotFound,
  InvalidFile,
};
