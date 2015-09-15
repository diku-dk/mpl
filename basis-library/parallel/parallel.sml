structure MLtonParallel :> MLTON_PARALLEL =
struct

  structure Basic : MLTON_PARALLEL_BASIC = MLtonParallelBasic
  structure ForkJoin : MLTON_PARALLEL_FORKJOIN = MLtonParallelForkJoin
  structure Array : MLTON_PARALLEL_ARRAY = MLtonParallelArray
  structure FutureSuspend : MLTON_PARALLEL_FUTURE = MLtonParallelFutureSuspend
  structure FutureSuspendDelay : MLTON_PARALLEL_FUTURE = MLtonParallelFutureSuspendDelay
  structure FutureSuspendMaybeDelay : MLTON_PARALLEL_FUTURE = MLtonParallelFutureSuspendMaybeDelay
  structure SyncVarSuspend : MLTON_PARALLEL_SYNCVAR = MLtonParallelSyncVarSuspend
  (* structure IO : MLTON_PARALLEL_IO = MLtonParallelIOSuspend *)
(*
  structure FutureCapture : MLTON_PARALLEL_FUTURE = MLtonParallelFutureCapture
  structure FutureCaptureDelay : MLTON_PARALLEL_FUTURE = MLtonParallelFutureCaptureDelay
  structure FutureCaptureMaybeDelay : MLTON_PARALLEL_FUTURE = MLtonParallelFutureCaptureMaybeDelay
*)
end
