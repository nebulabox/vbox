/** @file
  Internal include file of DXE CPU IO2 Library.

  Copyright (c) 2010, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials are licensed and made available
  under the terms and conditions of the BSD License which accompanies this
  distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef _DXE_CPUIO2_LIB_INTERNAL_H_
#define _DXE_CPUIO2_LIB_INTERNAL_H_

#include <PiDxe.h>

#include <Protocol/CpuIo2.h>

#include <Library/IoLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseLib.h>


/**
  Reads registers in the EFI CPU I/O space.

  Reads the I/O port specified by Port with registers width specified by Width.
  The read value is returned. If such operations are not supported, then ASSERT().
  This function must guarantee that all I/O read and write operations are serialized.

  @param  Port          The base address of the I/O operation.
                        The caller is responsible for aligning the Address if required.
  @param  Width         The width of the I/O operation.

  @return Data read from registers in the EFI CPU I/O space.

**/
UINT64
EFIAPI
IoReadWorker (
  IN      UINTN                     Port,
  IN      EFI_CPU_IO_PROTOCOL_WIDTH Width
  );

/**
  Writes registers in the EFI CPU I/O space.

  Writes the I/O port specified by Port with registers width and value specified by Width
  and Data respectively.  Data is returned. If such operations are not supported, then ASSERT().
  This function must guarantee that all I/O read and write operations are serialized.

  @param  Port          The base address of the I/O operation.
                        The caller is responsible for aligning the Address if required.
  @param  Width         The width of the I/O operation.
  @param  Data          The value to write to the I/O port.

  @return The paramter of Data.

**/
UINT64
EFIAPI
IoWriteWorker (
  IN      UINTN                     Port,
  IN      EFI_CPU_IO_PROTOCOL_WIDTH Width,
  IN      UINT64                    Data
  );

/**
  Reads memory-mapped registers in the EFI system memory space.

  Reads the MMIO registers specified by Address with registers width specified by Width.
  The read value is returned. If such operations are not supported, then ASSERT().
  This function must guarantee that all MMIO read and write operations are serialized.

  @param  Address       The MMIO register to read.
                        The caller is responsible for aligning the Address if required.
  @param  Width         The width of the I/O operation.

  @return Data read from registers in the EFI system memory space.

**/
UINT64
EFIAPI
MmioReadWorker (
  IN      UINTN                     Address,
  IN      EFI_CPU_IO_PROTOCOL_WIDTH Width
  );

/**
  Writes memory-mapped registers in the EFI system memory space.

  Writes the MMIO registers specified by Address with registers width and value specified by Width
  and Data respectively. Data is returned. If such operations are not supported, then ASSERT().
  This function must guarantee that all MMIO read and write operations are serialized.

  @param  Address       The MMIO register to read.
                        The caller is responsible for aligning the Address if required.
  @param  Width         The width of the I/O operation.
  @param  Data          The value to write to the I/O port.

  @return Data read from registers in the EFI system memory space.

**/
UINT64
EFIAPI
MmioWriteWorker (
  IN      UINTN                     Address,
  IN      EFI_CPU_IO_PROTOCOL_WIDTH Width,
  IN      UINT64                    Data
  );

#endif
